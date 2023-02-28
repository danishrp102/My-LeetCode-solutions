// Problem link: https://leetcode.com/problems/find-duplicate-subtrees/description/

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

    string solve(TreeNode *root, unordered_map <string, int> &mp, vector <TreeNode*> &ans) {
        if(!root)
            return "*";

        string l = solve(root->left, mp, ans);
        string r = solve(root->right, mp, ans);

        string cur = to_string(root->val) + "*" + l + "*" + r;

        if(mp[cur] == 1)
            ans.push_back(root);
        mp[cur]++;

        return cur;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector <TreeNode*> ans;
        unordered_map <string, int> mp;

        solve(root, mp, ans);

        return ans;
    }
};
