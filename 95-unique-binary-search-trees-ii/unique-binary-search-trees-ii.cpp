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
    vector<TreeNode*> solve(int start, int end, unordered_map<string, vector<TreeNode*>> &dp){
        vector<TreeNode*> trees;
        if(start > end){
            trees.push_back(nullptr);
            return trees;
        }

        string key = to_string(start) + "saksham" + to_string(end);
        if(dp.count(key)) return dp[key];

        for(int i = start; i<=end; i++){
            vector<TreeNode*> lefts = solve(start, i-1, dp);
            vector<TreeNode*> rights = solve(i+1, end, dp);

            for(TreeNode* leftn:lefts){
                for(TreeNode* rightn:rights){
                    TreeNode* root = new TreeNode(i);
                    root->left = leftn;
                    root->right = rightn;
                    trees.push_back(root);
                }
            }
        }

        return dp[key] = trees;
    }
    vector<TreeNode*> generateTrees(int n) {
        // idea: for left: go from start to i-1
        // right: go from i+1 to end
        // and keep forming trees using the vectors and keep pushing it in the main one
        if(n == 0) return vector<TreeNode*>();

        unordered_map<string, vector<TreeNode*>> dp;
        return solve(1, n, dp);
    }
};