// Problem link: https://leetcode.com/problems/count-sub-islands/description/

class Solution {
public:

    bool check(int x, int y, vector <vector <int> > &grid, int m, int n) {
        return (min(x, y) >= 0 && x < m && y < n);
    }

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid2[i][j] == 1)
                    grid2[i][j] = 2;
                grid1[i][j] += grid2[i][j];
            }
        }

        int ans = 0, t = 1;
        vector <vector <bool> > vis(m, vector <bool>(n, false));
        vector <vector <int> > time(m, vector <int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(!vis[i][j] && grid1[i][j] == 3) {
                    queue <pair <int, int> > q;
                    q.push(make_pair(i, j));
                    vis[i][j] = true;
                    time[i][j] = t;

                    bool stat = true;

                    while(!q.empty() && stat) {
                        auto [u, v] = q.front();
                        q.pop();

                        for(int k = 0; k < 4; k++) {
                            int nx = u + dx[k], ny = v + dy[k];

                            if(check(nx, ny, grid1, m, n)) {
                                if(grid1[nx][ny] == 2 || (grid1[nx][ny] == 3 && vis[nx][ny]) && time[nx][ny] != t) {
                                    stat = false;
                                    break;
                                }

                                else if(grid1[nx][ny] == 3 && !vis[nx][ny]) {
                                    vis[nx][ny] = true;
                                    q.push(make_pair(nx, ny));
                                    time[nx][ny] = t;
                                }
                            }
                        }

                    }

                    if(stat)
                        ans++;

                    t++;
                }
            }
        }

        return ans;
    }
};
