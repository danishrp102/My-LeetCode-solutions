// Problem link: https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/description/

class Solution {
private:
    int dx[3] = {-1, 0, 1};
    
    int check(int i, int j, vector <vector <int> > &grid, int &m, int val) {
        return (i >= 0 && i < m && val < grid[i][j]);
    }
    
    int solve(int i, int j, vector <vector <int> > &grid, int &m, int &n, vector <vector <int> > &dp) {
        if(j == n - 1)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        vector <int> maxi(3, 0);
        for(int k = 0; k < 3; k++) {
            if(check(i + dx[k], j + 1, grid, m, grid[i][j]))
                maxi[k] = 1 + solve(i + dx[k], j + 1, grid, m, n, dp);
        }
        
        return dp[i][j] = *max_element(maxi.begin(), maxi.end());
    }
    
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector <vector <int> > dp(m + 1, vector <int>(n + 1, -1));
        
        for(int i = 0; i < m; i++)
            ans = max(ans, solve(i, 0, grid, m, n, dp));
        
        return ans;
    }
};
