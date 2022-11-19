// Problem Link: https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/description/

class Solution {
public:
    int findIntegers(int n) {
        vector <int> dp0(32, 0), dp1(32, 0), dp(32, 0);
        dp0[0] = dp[0] = 1;

        for(int i = 1; i < 32; i++) {
            dp0[i] = dp0[i - 1] + dp1[i - 1];
            dp1[i] = dp0[i - 1];
            dp[i] = dp0[i] + dp1[i];
        }

        int prev = -1, ans = 0;
        for(int i = 30; i >= 0; i--) {
            int val = (n >> i) & 1;
            if(val == 1) {
                ans += dp[i];
                if(prev == 1)
                    return ans;
            }
            prev = val;
        }

        return ans + 1;
    }
};
