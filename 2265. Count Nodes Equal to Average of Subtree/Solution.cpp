// Problem link: https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/description/

class Solution {
public:

    pair <int, int> solve(TreeNode* root, int &ans) {
        if(!root->left && !root->right) {
            ans++;
            return {root->val, 1};
        }

        pair <int, int> l = {0, 0}, r = {0, 0};

        if(root->left)
            l = solve(root->left, ans);
        
        if(root->right)
            r = solve(root->right, ans);

        int sum = l.first + r.first + root->val;
        int n = l.second + r.second + 1;
        double a = (double)sum / (double)n;
        int avg = floor(a);

        if(avg == root->val)
            ans++;
        
        return {sum, n};
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        solve(root, ans);

        return ans;
    }
};
