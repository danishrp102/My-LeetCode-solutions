// Problem link: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/

class Solution {
public:

    int solve(vector <int> &arr, int i, int j, vector <vector <int> > &dp) {
        if(i == j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int mini = INT_MAX;
        for(int k = i; k < j; k++) {
            int ans1 = solve(arr, i, k, dp);
            int ans2 = solve(arr, k + 1, j, dp);

            int maxi1 = *max_element(arr.begin() + i, arr.begin() + k + 1);
            int maxi2 = *max_element(arr.begin() + k + 1, arr.begin() + j + 1);

            mini = min(mini, (maxi1 * maxi2) + ans1 + ans2);
        }

        return dp[i][j] = mini;
    }

    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();

        vector <vector <int> > dp(n + 1, vector <int>(n + 1, -1));
        return solve(arr, 0, n - 1, dp);
    }
};
