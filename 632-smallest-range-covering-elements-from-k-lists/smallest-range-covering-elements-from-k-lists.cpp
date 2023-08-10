class ele{
public:
    int data;
    int row;
    int col;
    ele(int d, int r, int c){
        data = d;
        row = r;
        col = c;
    }
};

class compare{
public:
    bool operator()(ele* a, ele* b){
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& arr) {
        // idea: is to put starting index in a min heap
        // to find the min and max ele
        // then to make the range smaller we need to inc the min ele
        // so just doing it using a custom data structure to get the next element
        int n = arr.size();
        // Step 1: make a min heap
        priority_queue<ele*, vector<ele*>, compare> pq;

        // Step 2: keep track of max ele
        int maxi = INT_MIN; 
        for(int i=0; i<n; i++){
            maxi = max(maxi, arr[i][0]);
            ele *temp = new ele(arr[i][0], i, 0);
            pq.push(temp);
        }

        // Step3: keep going till min heap is not empty
        vector<int> ans;
        int range = INT_MAX;
        while(!pq.empty()){
            ele *mini = pq.top(); // get the min ele
            pq.pop();
            
            // cout << maxi << " " << mini->data << " " << range << endl;

            // Step 3.1: if range is smaller then change the answer array
            if(range > abs(maxi - mini->data)){
                if(ans.size() > 1){
                    ans.pop_back();
                    ans.pop_back();
                }
                range = abs(maxi - mini->data);
                // cout << range << endl;
                ans.push_back(mini->data);
                ans.push_back(maxi);
            }

            // Step 3.2: add next ele to min if it exists
            int i = mini->row;
            int j = mini->col;
            int k = arr[i].size();
            if(j+1 < k){
                maxi = max(maxi, arr[i][j+1]);
                ele* temp = new ele(arr[i][j+1], i, j+1);
                pq.push(temp);
            }
            else break; // if doen't exist then break
        }

        return ans;
    }
};