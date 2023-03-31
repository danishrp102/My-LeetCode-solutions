// Problem link: https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/description/

class Solution {
public:

    const int mod = 1e9 + 7;

    int solve(vector <vector <int> > &pref, int cnt, int i, int j, int m, int n, vector <vector <vector <int> > > &dp) {

        if(cnt == 0)
            return (pref[m][n] - pref[i - 1][n] - pref[m][j - 1] + pref[i - 1][j - 1] > 0);

        if(dp[i][j][cnt] != -1)
            return dp[i][j][cnt];

        int ans = 0;
        for(int k = j + 1; k <= n; k++) {
            if(pref[m][k - 1] - pref[m][j - 1] - pref[i - 1][k - 1] + pref[i - 1][j - 1] > 0) {
                 ans = (ans + solve(pref, cnt - 1, i, k, m, n, dp)) % mod;
            } 
        }

        for(int k = i + 1; k <= m; k++) {
            if(pref[k - 1][n] - pref[i - 1][n] - pref[k - 1][j - 1] + pref[i - 1][j - 1] > 0) {
                ans = (ans + solve(pref, cnt - 1, k, j, m, n, dp)) % mod;
            }
        }

        return dp[i][j][cnt] = ans % mod;
    }

    int ways(vector<string>& pizza, int k) {
        int m = pizza.size(), n = pizza[0].size();
        vector <vector <int> > pref(m + 1, vector <int>(n + 1, 0));
        vector <vector <vector <int> > > dp(m + 1, vector <vector <int> > (n + 1, vector <int> (k, -1)));

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
                pref[i][j] += (pizza[i - 1][j - 1] == 'A') ? 1 : 0;
            }
        }

        return solve(pref, k - 1, 1, 1, m, n, dp);
    }
};
