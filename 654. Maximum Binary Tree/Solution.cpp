// Problem link: https://leetcode.com/problems/maximum-binary-tree/description/

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

    pair<int, int> ret_maxi(vector <int> &nums, int l, int r) {

        int maxi = INT_MIN, pos = -1;
        for(int i = l; i <= r; i++) {
            if(nums[i] > maxi)
                maxi = nums[i], pos = i;
        }
        
        return make_pair(maxi, pos);
    }

    void solve(TreeNode *root, int l1, int r1, int l2, int r2, vector <int> &nums) {
        if(r1 - l1 >= 0) {
            auto [maxi, pos] = ret_maxi(nums, l1, r1);
            root->left = new TreeNode(maxi);
            solve(root->left, l1, pos - 1, pos + 1, r1, nums);
        }

        if(r2 - l2 >= 0) {
            auto [maxi, pos] = ret_maxi(nums, l2, r2);
            root->right = new TreeNode(maxi);
            solve(root->right, l2, pos - 1, pos + 1, r2, nums);
        }
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        auto [maxi, pos] = ret_maxi(nums, 0, n - 1);
        TreeNode *root = new TreeNode(maxi);
        solve(root, 0, pos - 1, pos + 1, n - 1, nums);

        return root;
    }
};
