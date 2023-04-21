// Problem link: https://leetcode.com/problems/profitable-schemes/description/

class Solution {
private:
    const int mod = 1e9 + 7;

    int solve(int m, int n, int needed, vector <int> &wt, vector <int> &val, vector <vector <vector <int> > > &dp) {
        
        if(n < 0)
            return 0;
        
        if(m == 0) {
            if(needed == 0) // the smallest value 'needed' can take
                return 1;
            return 0;
        }

        if(dp[m][n][needed] != -1)
            return dp[m][n][needed];

        int take = 0, notTake = 0;
        notTake = solve(m - 1, n, needed, wt, val, dp);
        take = solve(m - 1, n - wt[m - 1], max(needed - val[m - 1], 0), wt, val, dp);
        
        return dp[m][n][needed] = (take % mod + notTake % mod) % mod;
    }

public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = group.size();
        vector <vector <vector <int> > > dp(m + 1, vector <vector <int> >(n + 1, vector <int>(minProfit + 1, -1)));
        return solve(m, n, minProfit, group, profit, dp);
    }
};
