// Problem link: https://leetcode.com/problems/make-costs-of-paths-equal-in-a-binary-tree/description/

// Solution1: (own)

class Solution {
private:
    int solve1(vector <int> &cost, int &n, int i, vector <int> &dp) {
        if(i > n)
            return 0;
        
        int l = solve1(cost, n, 2 * i, dp);
        int r = solve1(cost, n, 2 * i + 1, dp);
        
        dp[i] = max(l, r);
        return cost[i - 1] + dp[i];
    }
    
    void solve2(vector <int> &cost, int &n, int i, vector <int> &dp, int &ans, int &need, int sum) {
        if(i > n)
            return;
        
        sum += cost[i - 1];
        int tmp = need - (sum + dp[i]);
        ans += tmp;
        sum += tmp;
        
        solve2(cost, n, 2 * i, dp, ans, need, sum);
        solve2(cost, n, 2 * i + 1, dp, ans, need, sum);
    }
    
public:
    int minIncrements(int n, vector<int>& cost) {
        vector <int> dp(n + 1, 0);
        int need = solve1(cost, n, 1, dp);
        
        int ans = 0;
        solve2(cost, n, 1, dp, ans, need, 0);
        
        return ans;
    }
};

// Solution2: (learned)

class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0;
        
        for(int i = n / 2 - 1; i >= 0; i--) {
            int l = 2 * i + 1, r = 2 * i + 2;
            ans += abs(cost[l] - cost[r]);
            cost[i] += max(cost[l], cost[r]);
        }

        return ans;
    }
};
