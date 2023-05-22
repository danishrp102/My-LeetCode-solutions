// Problem link: https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/

class Solution {
private:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    bool check(int i, int j, vector <vector <int> > &grid, int &m, int &n, vector <vector <bool> > &vis) {
        return (min(i, j) >= 0 && i < m && j < n && grid[i][j] != 0 && !vis[i][j]);
    }
    
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        int ans = INT_MIN;
        
        vector <vector <bool> > vis(m, vector <bool>(n, false));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] != 0 && !vis[i][j]) {
                    queue <pair <int, int> > q;
                    int sum = 0;
                    
                    q.push(make_pair(i, j));
                    vis[i][j] = true;
                    
                    while(!q.empty()) {
                        auto [u, v] = q.front();
                        q.pop();
                        sum += grid[u][v];
                    
                         for(int k = 0; k < 4; k++) {
                             int nx = dx[k] + u, ny = dy[k] + v;
                             if(check(nx, ny, grid, m, n, vis)) {
                                 q.push(make_pair(nx, ny));
                                 vis[nx][ny] = true;
                             }
                        }
                        
                    }
                    
                    ans = max(ans, sum);
                }
            }
        }
        
        return (ans == INT_MIN) ? 0 : ans;
    }
};
