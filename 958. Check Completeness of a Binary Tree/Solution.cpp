// Problem link: https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/

class Solution {
public:

    int count(TreeNode *root) {
        if(!root)
            return 0;
        
        return 1 + count(root->left) + count(root->right);
    }

    bool solve(TreeNode *root, int i, int n) {
        if(!root)
            return true;
        
        if(i >= n)
            return false;
        return solve(root->left, 2 * i + 1, n) & solve(root->right, 2 * i + 2, n);
    }

    bool isCompleteTree(TreeNode* root) {
        int cnt = count(root);
        return solve(root, 0, cnt);
    }
};
