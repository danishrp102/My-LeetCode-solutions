// Problem link: https://leetcode.com/problems/maximize-win-from-two-segments/description/

class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size(), j = 0, ans = 0;
        vector <int> dp(n + 1, 0);

        for(int i = 0; i < n; i++) {
            while(prizePositions[i] - prizePositions[j] > k)
                j++;
            
            dp[i + 1] = max(dp[i], i - j + 1);
            ans = max(ans, i - j + 1 + dp[j]);
        }

        return ans;
    }
};
