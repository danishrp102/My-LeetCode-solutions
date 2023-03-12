// Problem link: https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/

class Solution {
public:
    
    void solve(TreeNode *root, int d, int &ans) {
        if(!root)
            return;
        
        ans = max(ans, d);
        solve(root->left, d + 1, ans);
        solve(root->right, d + 1, ans);
    }
    
    void get_sum(TreeNode *root, vector <long long> &sum, int d) {
        if(!root)
            return;
        
        sum[d] += root->val;
        get_sum(root->left, sum, d + 1);
        get_sum(root->right, sum, d + 1);
    }
    
    long long kthLargestLevelSum(TreeNode* root, int k) {

        int depth = 0;
        solve(root, 1, depth);
        vector <long long> sum(depth, 0);
        
        if(depth < k)
            return -1;
        
        get_sum(root, sum, 0);
        
        sort(sum.begin(), sum.end(), greater <long long>());
        return sum[k - 1];
    }
};
