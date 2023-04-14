// Problem link: https://leetcode.com/problems/minimum-cost-for-tickets/description/

class Solution {
private:
    int solve(vector <bool> &v, int i, vector <int> &costs, vector <int> &dp) {
        if(i > 365)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];

        if(!v[i])
            return dp[i] = solve(v, i + 1, costs, dp);
        
        int a = solve(v, i + 1, costs, dp) + costs[0];
        int b = solve(v, i + 7, costs, dp) + costs[1];
        int c = solve(v, i + 30, costs, dp) + costs[2];

        return dp[i] = min(a, min(b, c));
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector <bool> v(366, false);

        for(auto x: days)
            v[x] = true;
        
        vector <int> dp(366, -1);
        
        return solve(v, 1, costs, dp);
    }
};
