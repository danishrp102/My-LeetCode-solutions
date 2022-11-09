1035 -> Uncrossed Lines
Problem link: https://leetcode.com/problems/uncrossed-lines/description/

Here I will be first discussing the brute force approach and why it fails and how to optimize the time complexity using 2 approaches:
  1) Top-down DP (Recursion + Memoization)
  2) Bottom-up DP (Tabulation)
  
This problem is nothing but a slight modification of the Longest Common Subsequence problem where the number of uncrossing lines represent the longest common subsequence between the two arrays.
Longest Common Subsequence: https://leetcode.com/problems/longest-common-subsequence/description/

Brute force approach:

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

TC: Runs in exponential time since we are checking each and every possibility.
SC: O(n) for the call stack.
