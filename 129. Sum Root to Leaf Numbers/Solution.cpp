// Problem link: https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

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
    
    void solve(TreeNode *root, int sum, int &ans) {
        sum += root->val;
        
        if(!root->left && !root->right) {
            ans += sum;
            return;
        }
        
        sum *= 10;
        if(root->left)
            solve(root->left, sum, ans);
        if(root->right)
            solve(root->right, sum, ans);
    }
    
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        solve(root, 0, ans);
        return ans;
    }
};
