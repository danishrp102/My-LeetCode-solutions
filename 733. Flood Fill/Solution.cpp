// Problem link: https://leetcode.com/problems/flood-fill/description/

class Solution {
public:

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool check(int i, int j, vector <vector <int> > &grid, int &m, int &n, int &val) {
        return (min(i, j) >= 0 && i < m && j < n && grid[i][j] == val);
    }

    void solve(int i, int j, vector <vector <int> > &grid, int &m, int &n, int &color, int &val) {
        grid[i][j] = color;

        for(int k = 0; k < 4; k++) {
            int nx = i + dx[k], ny = j + dy[k];
            if(check(nx, ny, grid, m, n, val))
                solve(nx, ny, grid, m, n, color, val);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size(), val = image[sr][sc];

        if(val == color)
            return image;

        solve(sr, sc, image, m, n, color, val);
        return image;
    }
};
