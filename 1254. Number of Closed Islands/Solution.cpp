// Problem link: https://leetcode.com/problems/number-of-closed-islands/description/

class Solution {
private:

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool check(int i, int j, int &m, int &n, vector <vector <int> > &grid, bool &stat) {
        if(min(i, j) < 0 || i >= m || j >= n || grid[i][j] == 1)
            return false;
        if((min(i, j) == 0 || i == m - 1 || j == n - 1) && grid[i][j] == 0)
            stat = true;
        return (grid[i][j] == 0);
    }

    void solve(int i, int j, vector <vector <int> > &grid, bool &stat, int &m, int &n) {
        grid[i][j] = 2;

        for(int k = 0; k < 4; k++) {
            int nx = i + dx[k], ny = j + dy[k];
            if(check(nx, ny, m, n, grid, stat))
                solve(nx, ny, grid, stat, m, n);
        }
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;

        bool stat;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    stat = false;
                    if(min(i, j) == 0 || j == n - 1 || i == m - 1)
                        stat = true;
                    solve(i, j, grid, stat, m, n);

                    if(!stat)
                        ans++;
                }
            }
        }

        return ans;
    }
};
