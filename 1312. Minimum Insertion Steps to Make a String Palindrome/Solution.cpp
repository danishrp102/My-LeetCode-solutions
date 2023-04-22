// Problem link: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

// Code 1:

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector <vector <int> > dp(2, vector <int>(n + 1, 0));

        for(int i = 1; i <= n; i++) {

            fill(dp[1].begin(), dp[1].end(), 0);
            for(int j = 1; j <= n; j++) {

                if(s[i - 1] == s[n - j])
                    dp[1][j] = 1 + dp[0][j - 1];
                else
                    dp[1][j] = max(dp[0][j], dp[1][j - 1]);
            }

            dp[0] = dp[1];
        }

        return n - dp[0][n];
    }
};

// Code 2:

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string str = s;
        reverse(str.begin(), str.end());
        vector <vector <int> > dp(2, vector <int>(n + 1, 0));

        for(int i = 1; i <= n; i++) {

            fill(dp[1].begin(), dp[1].end(), 0);
            for(int j = 1; j <= n; j++) {

                if(s[i - 1] == str[j - 1])
                    dp[1][j] = 1 + dp[0][j - 1];
                else
                    dp[1][j] = max(dp[0][j], dp[1][j - 1]);
            }

            dp[0] = dp[1];
        }

        return n - dp[0][n];
    }
};

// Code 3:

class Solution {
public:
    int minInsertions(string s) {
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

        return n - dp[n][n];
    }
};

// Code 4:

class Solution {
private:
    int solve(string &a, string &b, int m, int n, vector <vector <int> > &dp) {
        if(m == 0 || n == 0)
            return 0;
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        if(a[m - 1] == b[n - 1])
            return dp[m][n] = 1 + solve(a, b, m - 1, n - 1, dp);
        else
            return dp[m][n] = max(solve(a, b, m - 1, n, dp), solve(a, b, m, n - 1, dp));
    }

public:
    int minInsertions(string s) {
        string str = s;
        reverse(str.begin(), str.end());
        int n = s.size();

        vector <vector <int> > dp(n + 1, vector <int>(n + 1, -1));

        int lcs = solve(s, str, n, n, dp);
        return n - lcs;
    }
};
