// Problem link: https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp(n, 1), cnt(n, 1);

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {

                if(nums[i] > nums[j]) {

                    if(dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }

                    else if(dp[j] + 1 == dp[i])
                        cnt[i] += cnt[j];
                }
            }
        }

        int maxi = *max_element(dp.begin(), dp.end()), ans = 0;

        for(int i = 0; i < n; i++) {
            if(dp[i] == maxi)
                ans += cnt[i];
        }

        return ans;
    }
};
