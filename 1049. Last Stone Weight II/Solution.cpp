// Problem link: https://leetcode.com/problems/last-stone-weight-ii/description/
// use 0/1 Knapsack

// Code1: Memoized Recursion:

class Solution {
public:

    int solve(vector <int> &v, int n, int wt, vector <vector <int> > &dp) {
        if(n == 0 || wt == 0)
            return 0;
        
        if(dp[n][wt] != -1)
            return dp[n][wt];
        
        if(v[n - 1] <= wt)
            return dp[n][wt] = max(solve(v, n - 1, wt - v[n - 1], dp) + v[n - 1], solve(v, n - 1, wt, dp));

        else
            return dp[n][wt] = solve(v, n - 1, wt, dp);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);

        vector <vector <int> > dp(n + 1, vector <int> (sum / 2 + 1, -1));
        int ans = solve(stones, n, sum / 2, dp);

        return sum - 2 * ans;
    }
};

// Code2: Tabulation: 

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);

        vector <vector <int> > dp(n + 1, vector <int>(sum / 2 + 1, 0));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= sum / 2; j++) {
                if(stones[i - 1] <= j)
                    dp[i][j] = max(dp[i - 1][j - stones[i - 1]] + stones[i - 1], dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return sum - 2 * dp[n][sum / 2];
    }
};
