// Problem link: https://leetcode.com/problems/check-knight-tour-configuration/

class Solution {
public:
    
    int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
    int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};
    
    bool check(int i, int j, int &n, vector <vector <int> > &grid, int s) {
        return(min(i, j) >= 0 && max(i, j) < n && grid[i][j] == s);
    }
    
    bool solve(vector <vector <int> > &grid, int s, int &n, int i, int j) {
        if(s == n * n - 1)
            return true;
        
        for(int k = 0; k < 8; k++) {
            int nx = dx[k] + i;
            int ny = dy[k] + j;
            
            if(check(nx, ny, n, grid, s + 1)) {
                return solve(grid, s + 1, n, nx, ny);
                break;
            }
        }
        
        return false;
    }
    
    bool checkValidGrid(vector<vector<int>>& grid) {
        int start = 0;
        int n = grid.size();
        
        if(grid[0][0] == 0) {
            if(solve(grid, start, n, 0, 0))
                return true;
            else
                return false;
        }
        
        else
            return false;
    }
};
