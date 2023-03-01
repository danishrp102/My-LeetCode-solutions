// Problem link: https://leetcode.com/problems/partition-array-for-maximum-sum/description/

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector <int> dp(n + 1, 0);

        for(int i = 1; i <= n; i++) {
            int curr = 0, maxi = 0;
            for(int j = 1; j <= k && (i - j) >= 0; j++) {
                curr = max(curr, arr[i - j]);
                maxi = max(maxi, dp[i - j] + curr * j);
            }

            dp[i] = maxi;
        }

        return dp[n];
    }
};
