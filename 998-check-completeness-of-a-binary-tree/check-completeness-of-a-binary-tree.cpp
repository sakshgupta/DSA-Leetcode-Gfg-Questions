/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root){
        if(root == NULL) return 0;

        int ans = 1 + countNodes(root->left) + countNodes(root->right);

        return ans;
    }
    bool solve(TreeNode* root, int idx, int &totalCount){
        if(root == NULL) return true;
        
        if(idx >= totalCount) return false; // = as its 0 based indexing
        else{
            bool left = solve(root->left, idx*2+1, totalCount);
            bool right = solve(root->right, idx*2+2, totalCount);

            return left and right;
        }
    }

    // better using lot to go to each level and if found found null then found a valid node next to it that means its not a CBT
    bool solve_better_lot(TreeNode* root){
        if(root == NULL) return true;

        queue<TreeNode*> q;
        q.push(root);

        bool emptyFlag = false;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr == NULL){
                    emptyFlag = true;
                }
                else{
                    if(emptyFlag) return false;
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
        }
        return true;
    }
    bool isCompleteTree(TreeNode* root) {
        // idea: is to find the total count then go to each node with its index as it will be in a level order traversal then if its index > totalCount then return false
        // in lot: parent -> i, leftchild -> 2*i+1, rightchild -> 2*i+2 (0 based indexing)
        
        // int totalCount = countNodes(root);
        // return solve(root, 0, totalCount);
        return solve_better_lot(root);
    }
};