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
    void inorder(TreeNode* root, vector<int> &in){
        if(root == NULL) return;

        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }

    TreeNode* makeTree(vector<int> &in, int is, int ie){
        // select middle node from inorder and call for left tree and right tree
        if(is > ie) return NULL;

        // getting the middle element
        int mid = (is+ie)/2;
        TreeNode* midnode = new TreeNode(in[mid]);

        // as we have the middle now calling for the left and right parts
        midnode->left = makeTree(in, is, mid-1);
        midnode->right = makeTree(in, mid+1, ie);

        return midnode;
    }

    TreeNode* balanceBST(TreeNode* root) {
        // idea: is to make the inorder then make a bst from inorder
        vector<int> in;
        inorder(root, in);
        
        TreeNode* ans = makeTree(in, 0, in.size()-1);

        return ans;
    }
};