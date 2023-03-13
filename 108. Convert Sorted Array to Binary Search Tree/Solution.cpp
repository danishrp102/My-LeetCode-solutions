// Problem link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

class Solution {
public:

    int i;

    TreeNode *solve(int n, vector <int> &nums) {
        if(n == 0)
            return NULL;
        
        TreeNode *tmp = new TreeNode(0);
        tmp->left = solve(n / 2, nums);
        tmp->val = nums[i++];
        tmp->right = solve(n - n / 2 - 1, nums);
        return tmp;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        i = 0;
        return solve(n, nums);
    }
};
