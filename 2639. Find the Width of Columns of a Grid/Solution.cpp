// Problem link: https://leetcode.com/problems/find-the-width-of-columns-of-a-grid/description/

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector <int> ans(n);
        
        for(int j = 0; j < n; j++) {
            int mini = INT_MAX, maxi = INT_MIN;
            for(int i = 0; i < m; i++) {
                maxi = max(maxi, grid[i][j]);
                mini = min(mini, grid[i][j]);
            }
            
            string a = to_string(mini);
            string b = to_string(maxi);
            
            ans[j] = max(a.size(), b.size());
        }
        
        return ans;
    }
};
