// Problem link: https://leetcode.com/problems/restore-the-array/description/

// Memoization: 

class Solution {
private:

    const int mod = 1e9 + 7;

    int solve(string &s, int i, int &n, int &k, vector <int> &dp) {
        if(i == n)
            return 1;
        
        if(s[i] == '0')
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        long num = 0, ans = 0;

        for(int j = i; j < n; j++) {
            num *= 10;
            num += s[j] - '0';

            if(num <= k)
                ans = (ans % mod + solve(s, j + 1, n, k, dp) % mod) % mod;

            else
                break;
        }

        return dp[i] = ans % mod;
    }

public:
    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector <int> dp(n + 1, -1);
        return solve(s, 0, n, k, dp);
    }
};

// Tabulation: 

class Solution {
private:
    const int mod = 1e9 + 7;

public:
    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector <int> dp(n + 1, 0);

        dp[n] = 1;

        for(int i = n; i >= 1; i--) {
            long num = 0;
            int ans = 0;

            for(int j = i; j <= n; j++) {
                num *= 10;
                num += s[j - 1] - '0';

                if(num == 0 || num > k)
                    break;
                
                ans = (ans + dp[j]) % mod;
            }

            dp[i - 1] = ans;
        }

        return dp[0];
    }
};
