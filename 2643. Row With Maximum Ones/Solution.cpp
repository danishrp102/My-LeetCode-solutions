// Problem link: https://leetcode.com/problems/row-with-maximum-ones/description/

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int maxi = INT_MIN, pos = -1;
        
        for(int i = 0; i < m; i++) {
            int val = accumulate(mat[i].begin(), mat[i].end(), 0);
            
            if(val > maxi) {
                maxi = val;
                pos = i;
            }
        }
        
        vector <int> v{pos, maxi};
        return v;
    }
};
