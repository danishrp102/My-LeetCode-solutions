// Problem link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

class Solution {
public:

    void depth(TreeNode *root, int l, int &d) {
        if(!root)
            return;
        d = max(d, l);
        depth(root->left, l + 1, d);
        depth(root->right, l + 1, d);
    }

    void solve(TreeNode *root, int level, vector <vector <int> > &ans) {
        if(!root)
            return;
        solve(root->left, level + 1, ans);
        ans[level].push_back(root->val);
        solve(root->right, level + 1, ans);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int d = 0;
        depth(root, 1, d);
        vector <vector <int> > ans(d);
        solve(root, 0, ans);

        for(int i = 0; i < ans.size(); i++) {
            if(i & 1)
                reverse(ans[i].begin(), ans[i].end());
        }

        return ans;
    }
};
