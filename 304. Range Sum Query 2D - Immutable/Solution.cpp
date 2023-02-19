// Problem link: https://leetcode.com/problems/range-sum-query-2d-immutable/description/

class NumMatrix {

private:
    vector <vector <int> > pref_sum;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        pref_sum.resize(m + 1, vector <int>(n + 1, 0));

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++)
                pref_sum[i][j] = matrix[i - 1][j - 1] + pref_sum[i - 1][j] + pref_sum[i][j - 1] - pref_sum[i - 1][j - 1];
        }    
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return (pref_sum[row2 + 1][col2 + 1] + pref_sum[row1][col1] - pref_sum[row2 + 1][col1] - pref_sum[row1][col2 + 1]);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
