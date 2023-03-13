// Problem link: https://leetcode.com/problems/symmetric-tree/description/

class Solution {
public:

    bool solve(TreeNode *l, TreeNode *r) {
        if(!l && !r)
            return true;
        if(!l || !r || l->val != r->val)
            return false;
        return solve(l->left, r->right) & solve(l->right, r->left);
    }

    bool isSymmetric(TreeNode* root) {
        return solve(root->left, root->right);
    }
};
