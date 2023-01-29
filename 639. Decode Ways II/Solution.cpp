// Problem link: https://leetcode.com/problems/decode-ways-ii/description/

class Solution {
public:

    const long long int mod = 1e9 + 7;

    long long int solve(string &str, int n, vector <int> &dp) {
        if(n == 0)
            return 1;
        
        if(n == 1) {
            if(str[0] == '*')
                return 9;
            else if(str[0] != '0')
                return 1;
            else
                return 0;
        }

        if(dp[n] != -1)
            return dp[n];

        long long int ans = 0;

        if(str[n - 1] == '*')
            ans = (ans + 9 * solve(str, n - 1, dp)) % mod;
        else if(str[n - 1] != '0')
            ans = (ans + solve(str, n - 1, dp)) % mod;

        if(str[n - 2] == '*') {
            if(str[n - 1] == '*')
                ans = (ans + 15 * solve(str, n - 2, dp)) % mod;
            else if(str[n - 1] <= '6')
                ans = (ans + 2 * solve(str, n - 2, dp)) % mod;
            else
                ans = (ans + solve(str, n - 2, dp)) % mod;
        }

        else if(str[n - 2] == '1') {
            if(str[n - 1] == '*')
                ans = (ans + 9 * solve(str, n - 2, dp)) % mod;
            else
                ans = (ans + solve(str, n - 2, dp)) % mod;
        }

        else if(str[n - 2] == '2') {
            if(str[n - 1] == '*')
                ans = (ans + 6 * solve(str, n - 2, dp)) % mod;
            else if(str[n - 1] <= '6')
                ans = (ans + solve(str, n - 2, dp)) % mod;
        }

        return dp[n] = ans;    
    }

    int numDecodings(string s) {
        int n = s.size();
        vector <int> dp(n + 1, -1);

        return solve(s, n, dp);
    }
};
