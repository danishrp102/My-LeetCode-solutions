// Problem link: https://leetcode.com/problems/deepest-leaves-sum/description/

class Solution {
public:

    int depth(TreeNode *root) {
        if(!root)
            return 0;
        int dep1 = depth(root->left);
        int dep2 = depth(root->right);
        return 1 + max(dep1, dep2);
    }

    int solve(TreeNode *root, int h, int &d) {
        if(!root)
            return 0;
        if(h == d)
            return root->val;
        return solve(root->left, h + 1, d) + solve(root->right, h + 1, d);
    }

    int deepestLeavesSum(TreeNode* root) {
        int ht = depth(root);
        return solve(root, 1, ht);
    }
};
