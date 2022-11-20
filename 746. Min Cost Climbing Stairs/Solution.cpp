// Problem link: https://leetcode.com/problems/min-cost-climbing-stairs/description/?envType=study-plan&id=dynamic-programming-i



// Memoized Recursive Code:

class Solution {
public:

    int solve(int n, vector <int> &cost, vector <int> &dp) {
        if(n == 0)
            return cost[0];
        if(n == 1)
            return cost[1];
        if(dp[n] != -1)
            return dp[n];

        return dp[n] = cost[n] + min(solve(n - 1, cost, dp), solve(n - 2, cost, dp));
    } 

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector <int> dp(n, -1);
        int c1 = solve(n - 1, cost, dp);

        fill(dp.begin(), dp.end(), -1);
        int c2 = solve(n - 2, cost, dp);

        return min(c1, c2);
    }
};





// Tabular Code:


// O(n) space:

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector <int> dp(n, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i < n; i++)
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        return min(dp[n - 1], dp[n - 2]);
    }
};


// O(1) space:

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(), a = cost[0], b = cost[1], c;

        for(int i = 2; i < n; i++)
            c = cost[i] + min(a, b), a = b, b = c;
        return min(a, b);
    }
};
