// Problem link: https://leetcode.com/problems/find-all-groups-of-farmland/description/

class Solution {
public:

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    void solve(int i, int j, vector <vector <bool> > &vis, vector <vector <int> > &grid, vector <int> &v) {
        vis[i][j] = true;
        v[0] = min(v[0], i), v[1] = min(v[1], j);
        v[2] = max(v[2], i), v[3] = max(v[3], j);
        int m = grid.size(), n = grid[0].size();

        for(int k = 0; k < 4; k++) {
            int nx = i + dx[k], ny = j + dy[k];

            if(min(nx, ny) >= 0 && nx < m && ny < n && !vis[nx][ny] && grid[nx][ny] == 1)
                solve(nx, ny, vis, grid, v);
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        vector <vector <bool> > vis(m, vector <bool>(n, false));
        vector <vector <int> > ans;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(land[i][j] == 1 && !vis[i][j]) {
                    vector <int> v(4);
                    v[0] = v[1] = INT_MAX;
                    v[2] = v[3] = INT_MIN;

                    solve(i, j, vis, land, v);
                    ans.push_back(v);
                }
            }
        }

        return ans;
    }
};
