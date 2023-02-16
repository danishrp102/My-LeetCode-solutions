// Problem link: https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

class Solution {
public:

    void solve(TreeNode *root, int &ht, int h) {
        if(!root)
            return;
        
        h++;
        ht = max(h, ht);
        solve(root->left, ht, h);
        solve(root->right, ht, h);
    }

    int maxDepth(TreeNode* root) {
        int ht = 0;
        solve(root, ht, 0);
        return ht;
    }
};
