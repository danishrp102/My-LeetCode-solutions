// Problem link: https://leetcode.com/problems/house-robber-ii/description/

The main difference between this problem and its predecessor is that in this version the first and the last houses are also neighbours
We can use the same code for the previous variant by modifying this problem by categorizing it into 2 cases:
Case 1) The last house is robbed, meaning the robber cannot rob the first house
Case 2) The last house is not robbed, meaning the robber is free to rob the first house

class Solution {
public:

    int solve(int n, vector <int> &nums, vector <int> &dp, bool &flag) {
        if(n == 0) {
            if(flag)
                return nums[0];
            else
                return 0;
        }

        if(n < 0) 
            return 0;
        if(dp[n] != -1)
            return dp[n];
        return dp[n] = max(solve(n - 1, nums, dp, flag), nums[n] + solve(n - 2, nums, dp, flag));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp(n, -1);
        bool flag = false;

        int m1 = solve(n - 3, nums, dp, flag) + nums[n - 1];
        fill(dp.begin(), dp.end(), -1);
        flag = true;
        int m2 = solve(n - 2, nums, dp, flag);

        return max(m1, m2);
    }
};
