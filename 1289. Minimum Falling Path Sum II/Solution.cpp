// Problem link: https://leetcode.com/problems/minimum-falling-path-sum-ii/description/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        if(n == 1)
            return grid[0][0];
        
        vector <vector <int> > dp(n, vector <int>(n, INT_MAX));
        for(int j = 0; j < n; j++)
            dp[0][j] = grid[0][j];
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    if(j == k)
                        continue;
                    dp[i][j] = min(dp[i][j], dp[i - 1][k]);
                }

                dp[i][j] += grid[i][j];
            }
        }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};
