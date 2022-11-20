// Problem link: https://leetcode.com/problems/jump-game/description/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector <bool> dp(n, false);
        dp[0] = true;
        for(int i = 0; i < n; i++) {
            if(!dp[i])
                continue;
            
            int jump = nums[i];
            for(int j = 1; j <= jump; j++) {
                if(i + j >= n)
                    break;
                dp[i + j] = true;
            }
        }
        
        return dp[n - 1];
    }
};
