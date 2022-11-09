class Solution {
public:

    int solve(vector <int> &A, vector <int> &B, int m, int n) {
        if(m == 0 || n == 0)
            return 0;
        if(A[m - 1] == B[n - 1])
            return 1 + solve(A, B, m - 1, n - 1);
        else
            return max(solve(A, B, m - 1, n), solve(A, B, m, n - 1));
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        return solve(nums1, nums2, m, n);
    }
};
