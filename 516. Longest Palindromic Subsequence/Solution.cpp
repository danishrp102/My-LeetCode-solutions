// Problem link: https://leetcode.com/problems/longest-palindromic-subsequence/description/

// Tabulation

class Solution {
public:

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string str = s;
        reverse(str.begin(), str.end());
        vector <vector <int> > dp(n + 1, vector <int>(n + 1, 0));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i - 1] == str[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][n];
    }
};

// Memoization

class Solution {
public:

    int solve(string &a, int m, string &b, int n, vector <vector <int> > &dp) {
        if(m == 0 || n == 0)
            return 0;
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        if(a[m - 1] == b[n - 1])
            return dp[m][n] = 1 + solve(a, m - 1, b, n - 1, dp);

        else
            return dp[m][n] = max(solve(a, m - 1, b, n, dp), solve(a, m, b, n - 1, dp));
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string str = s;
        reverse(str.begin(), str.end());
        vector <vector <int> > dp(n + 1, vector <int>(n + 1, -1));

        return solve(s, n, str, n, dp);
    }
};
