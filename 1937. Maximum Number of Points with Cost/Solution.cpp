// Problem link: https://leetcode.com/problems/maximum-number-of-points-with-cost/description/

class Solution {
public:

    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector <vector <long long> > dp(m, vector <long long>(n, 0ll));
        
        for(int j = 0; j < n; j++)
            dp[0][j] = points[0][j];

        for(int i = 1; i < m; i++) {

            vector <long long> l_dp(n, -1), r_dp(n, -1);
            l_dp[0] = dp[i - 1][0] + 0;
            r_dp[n - 1] = dp[i - 1][n - 1] - (n - 1);

            for(int k = 1; k < n; k++)
                l_dp[k] = max(l_dp[k - 1], dp[i - 1][k] + k);
            
            for(int k = n - 2; k >= 0; k--)
                r_dp[k] = max(r_dp[k + 1], dp[i - 1][k] - k);

            for(int j = 0; j < n; j++) {
               dp[i][j] = max(l_dp[j] - j, r_dp[j] + j) + points[i][j];
            }
        }

        long long ans = *max_element(dp[m - 1].begin(), dp[m - 1].end());
        return ans;
    }
};
