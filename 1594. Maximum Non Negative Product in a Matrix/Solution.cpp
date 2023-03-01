// Problem link: https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/description/

class Solution {
public:

    const int mod = 1e9 + 7;

    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector <vector <pair <long long, long long> > > dp(m, vector <pair <long long, long long> >(n));
        dp[0][0] = make_pair(grid[0][0], grid[0][0]);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) {
                    dp[0][0] = make_pair(grid[0][0], grid[0][0]);
                    continue;
                }

                auto up = (i > 0) ? dp[i - 1][j] : dp[i][j - 1];
                auto left = (j > 0) ? dp[i][j - 1] : dp[i - 1][j];

                long long maxi = max(up.first, left.first), mini = min(up.second, left.second);
                if(grid[i][j] < 0)
                    swap(maxi, mini);
                dp[i][j].first = grid[i][j] * maxi;
                dp[i][j].second = grid[i][j] * mini;
            }
        }

        return (dp[m - 1][n - 1].first >= 0) ? dp[m - 1][n - 1].first % mod : -1;
    }
};
