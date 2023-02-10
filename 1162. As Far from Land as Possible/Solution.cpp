// Problem link: https://leetcode.com/problems/as-far-from-land-as-possible/description/

class Solution {
public:

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool check(int i, int j, int &m, int &n, vector <vector <int> > &grid) {
        return (min(i, j) >= 0 && i < m && j < n && grid[i][j] == 0);
    }

    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        queue <pair <int, int> > q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1)
                    q.push(make_pair(i, j));
            }
        }

        while(!q.empty()) {
            int siz = q.size();

            for(int i = 0; i < siz; i++) {
                auto [x, y] = q.front();
                q.pop();

                for(int k = 0; k < 4; k++) {
                    int nx = dx[k] + x, ny = dy[k] + y;

                    if(check(nx, ny, m, n, grid)) {
                        grid[nx][ny] = grid[x][y] + 1;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }

        int ans = INT_MIN;
        for(int i = 0; i < m; i++)
            ans = max(ans, *max_element(grid[i].begin(), grid[i].end()));
        
        return (ans <= 1) ? -1 : (ans - 1);
    }
};
