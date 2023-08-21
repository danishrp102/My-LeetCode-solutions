// Problem link: https://leetcode.com/problems/sorting-three-groups/

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        int n = nums.size();
        vector <int> dp(n, 1); // Longest Non-decreasing subsequence

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] >= nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        int tmp = *max_element(dp.begin(), dp.end());
        return n - tmp;
    }
};
