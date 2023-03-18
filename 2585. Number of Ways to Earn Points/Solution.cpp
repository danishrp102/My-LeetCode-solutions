// Problem link: https://leetcode.com/problems/number-of-ways-to-earn-points/description/

class Solution {
public:

    const int mod = 1e9 + 7;

    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        vector <int> dp(target + 1, 0);
        dp[0] = 1;

        for(int i = 0; i < n; i++) {
            for(int j = target; j >= 0; j--) {
                for(int k = types[i][1]; k <= types[i][1] * types[i][0] && k <= j; k += types[i][1]) {
                    dp[j] = (dp[j] + dp[j - k]) % mod;
                }
            }
        }

        return dp[target];
    }
};
