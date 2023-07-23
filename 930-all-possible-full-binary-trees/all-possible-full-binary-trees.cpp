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
    vector<TreeNode*> solve(int n, vector<vector<TreeNode*>> &dp){
        // we go from 1 to n then just call for left(i) and right(n-i-1)
        // for each left and right vector append it in the current vector 

        // base case
        if(n % 2 == 0) return {}; // as even n can't be divided into 2 childs and a parent

        if(dp[n].size() != 0) return dp[n];

        vector<TreeNode*> v;
        if(n == 1) v.push_back(new TreeNode(0)); // if n is 1 then only one possiblity

        for(int i=1; i<n; i++){
            vector<TreeNode*> leftNodes = solve(i, dp);
            vector<TreeNode*> rightNodes = solve(n-i-1, dp); // sub i for left and 1 for right
            for(auto lf:leftNodes){
                for(auto rf:rightNodes){
                    v.push_back(new TreeNode(0, lf, rf));
                }
            }
        }

        return dp[n] = v;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        // idea: is to call for left subtree and right subtree to make their trees
        // The recursion works by first generating all possible full binary trees with i nodes, and then all possible full binary trees with n - i - 1 nodes. 
        vector<vector<TreeNode*>> dp;
        dp.resize(n+1);
        return solve(n, dp);
    }
};