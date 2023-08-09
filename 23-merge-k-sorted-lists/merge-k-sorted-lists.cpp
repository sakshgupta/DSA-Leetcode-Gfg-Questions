/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class ele{
public:
    int data;
    ListNode *ll;
    ele(int d, ListNode *node){
        data = d;
        ll = node;
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
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        int n = arr.size();
        ListNode *ans = new ListNode(-1);
        ListNode *tail = ans;
        priority_queue<ele*, vector<ele*>, compare> pq;

        for(int i=0; i<n; i++){
            if(arr[i] != NULL){
                ele *temp = new ele(arr[i]->val, arr[i]);
                pq.push(temp);
            }
        }

        while(!pq.empty()){
            ele *curr = pq.top();
            tail->next = new ListNode(curr->data);
            tail = tail->next;
            // cout << curr->data << endl;
            pq.pop();
            
            if(curr->ll->next != NULL){
                ele *temp = new ele(curr->ll->next->val, curr->ll->next);
                pq.push(temp);
            }
        }

        return ans->next;
    }
};