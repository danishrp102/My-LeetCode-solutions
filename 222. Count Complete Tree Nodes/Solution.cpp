class Solution {
public:

    int solve(TreeNode *root) {
        if(!root)
            return 0;
        int a = solve(root->left);
        int b = solve(root->right);
        return 1 + a + b;
    }

    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        return solve(root);
    }
};
