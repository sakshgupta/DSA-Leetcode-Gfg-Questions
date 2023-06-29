class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.length();
        vector<int> rmax(n, -1);

        rmax[n-1] = n-1;
        for(int i=n-2; i>=0; i--){
            if(rmax[i+1] != -1 and (str[rmax[i+1]] >= str[i])) {
                rmax[i] = rmax[i+1];
            }
            else rmax[i] = i;
                // cout << rmax[i] << endl;
        }

        for(int i=0; i<n; i++){
            if(rmax[i] != -1)
                if(str[i] < str[rmax[i]]) {
                    swap(str[i], str[rmax[i]]);
                    break;
                }
        }

        return stoi(str);
    }
};