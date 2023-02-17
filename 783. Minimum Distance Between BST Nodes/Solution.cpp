// Solution link: https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/

class Solution {
public:

    void solve(TreeNode *root, vector <int> &inorder) {
        if(!root)
            return;
        
        solve(root->left, inorder);
        inorder.push_back(root->val);
        solve(root->right, inorder);
    } 

    int minDiffInBST(TreeNode* root) {
        vector <int> v;
        solve(root, v);
        int n = v.size(), mini = INT_MAX;;

        for(int i = 1; i < n; i++)
            mini = min(mini, v[i] - v[i - 1]);
        
        return mini;
    }
};
