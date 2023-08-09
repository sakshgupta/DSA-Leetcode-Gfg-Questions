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

// Similar question to
// https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

// we need this class so as to store the data and the linked list for easy use
class ele{
public:
    int data;
    ListNode *ll;
    ele(int d, ListNode *node){
        data = d;
        ll = node;
    }
};

// compare class becoz in minheap just greater<int> won't work on custom data structure
class compare{
public:
    bool operator()(ele* a, ele* b){
        return a->data > b->data;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        // idea: is to create a min heap
        // then push starting linked list of each array in the min heap
        // then push the next element next to the min ele in the heap
        // continue till its empty
        
        // Step 1: create a minheap
        int n = arr.size();
        ListNode *ans = new ListNode(-1);
        ListNode *tail = ans;
        priority_queue<ele*, vector<ele*>, compare> pq; // greater<int> won't work on custom data struc.

        // Step2: insert first elements of all arrays in the minheap
        for(int i=0; i<n; i++){
            if(arr[i] != NULL){
                ele *temp = new ele(arr[i]->val, arr[i]);
                pq.push(temp);
            }
        }

        // Step3: till pq is empty
        while(!pq.empty()){
            // Step3.1: find the min ele and push it in the ans array
            ele *curr = pq.top();
            tail->next = new ListNode(curr->data);
            tail = tail->next;
            // cout << curr->data << endl;
            pq.pop();
            
            // Step3.2: add next element in the same row if its exists
            if(curr->ll->next != NULL){
                ele *temp = new ele(curr->ll->next->val, curr->ll->next);
                pq.push(temp);
            }
        }

        return ans->next;
    }
};