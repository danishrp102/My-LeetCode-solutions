// Problem link: https://leetcode.com/problems/number-of-enclaves/description/

class Solution {
public:

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int solve(int i, int j, vector <vector <int> > &grid, bool &flag, int &m, int &n) {
        grid[i][j] = 2;
        int cnt = 0;

        if(min(i, j) == 0 || (i == m - 1) || (j == n - 1))
            flag = true;

        for(int k = 0; k < 4; k++) {
            int nx = i + dx[k], ny = j + dy[k];

            if(min(nx, ny) >= 0 && nx < m && ny < n && grid[nx][ny] == 1)
                cnt += solve(nx, ny, grid, flag, m, n);
        }

        return cnt + 1;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1) {
                    bool flag = false;
                    int cnt = solve(i, j, grid, flag, m, n);

                    if(!flag)
                        ans += cnt;
                }
            }
        }

        return ans;
    }
};
