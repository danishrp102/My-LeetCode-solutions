// Problem link: https://leetcode.com/problems/number-of-enclaves/description/

class Solution {
public:

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int solve(int i, int j, vector <vector <bool> > &vis, vector <vector <int> > &grid, bool &flag) {
        vis[i][j] = true;
        int cnt = 0, m = grid.size(), n = grid[0].size();

        if(min(i, j) == 0 || (i == m - 1) || (j == n - 1))
            flag = true;

        for(int k = 0; k < 4; k++) {
            int nx = i + dx[k], ny = j + dy[k];

            if(min(nx, ny) >= 0 && nx < m && ny < n && grid[nx][ny] == 1 && !vis[nx][ny]) {
                cnt += solve(nx, ny, vis, grid, flag);
            }
        }

        return cnt + 1;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        vector <vector <bool> > vis(m, vector <bool>(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(!vis[i][j] && grid[i][j] == 1) {
                    bool flag = false;
                    int cnt = solve(i, j, vis, grid, flag);

                    if(!flag)
                        ans += cnt;
                }
            }
        }

        return ans;
    }
};
