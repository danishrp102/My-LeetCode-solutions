class Solution {
public:

    int solve(vector <int> &A, vector <int> &B, int m, int n, vector <vector <int> > &dp) {
        if(m == 0 || n == 0)
            return 0;
        if(dp[m][n] != -1)
            return dp[m][n];
        if(A[m - 1] == B[n - 1])
            return dp[m][n] = 1 + solve(A, B, m - 1, n - 1, dp);
        else
            return dp[m][n] = max(solve(A, B, m - 1, n, dp), solve(A, B, m, n - 1, dp));
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector <vector <int> > dp(m + 1, vector <int>(n + 1, -1));
        return solve(nums1, nums2, m, n, dp);
    }
};
