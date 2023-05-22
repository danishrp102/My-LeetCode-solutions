// Problem link: https://leetcode.com/problems/first-completely-painted-row-or-column/description/

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map <int, pair <int, int> > mp;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
                mp[mat[i][j]] = make_pair(i, j);
        }
        
        vector <int> row(n, m), col(m, n);
        
        for(int i = 0; i < m * n; i++) {
            row[mp[arr[i]].second]--;
            col[mp[arr[i]].first]--;
            
            if(row[mp[arr[i]].second] == 0 || col[mp[arr[i]].first] == 0)
                return i;
        }
        
        return -1;
    }
};
