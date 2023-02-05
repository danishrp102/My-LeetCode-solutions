// Problem link: https://leetcode.com/problems/detect-cycles-in-2d-grid/description/

class Solution {
public:

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool check(int i, int j, vector <vector <char> > &grid, int &m, int &n, int &cnt, char &ch) {
        return (min(i, j) >= 0 && i < m && j < n && grid[i][j] == ch);          
    }

    bool solve(int i, int j, int x, int y, vector <vector <int> > &vis, vector <vector <char> > &grid, int &m, int &n, int &c) {
        vis[i][j] = c;

        for(int k = 0; k < 4; k++) {
            int nx = dx[k] + i, ny = dy[k] + j;
            if(nx == x && ny == y)
                continue;
            
            bool val = check(nx, ny, grid, m, n, c, grid[i][j]);

            if(val) {
                if(vis[nx][ny] == c)
                    return true;
                else {
                    bool stat = solve(nx, ny, i, j, vis, grid, m, n, c);
                    if(stat)
                        return true;
                }
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), counter = 0;
        vector <vector <int> > vis(m, vector <int>(n, -1));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(vis[i][j] == -1) {
                    counter++;
                    if(solve(i, j, -1, -1, vis, grid, m, n, counter))
                        return true;
                }
            }
        }

        return false;
    }
};
