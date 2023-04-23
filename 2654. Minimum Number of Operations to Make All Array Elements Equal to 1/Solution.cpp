// Problem link: https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/description/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = count(nums.begin(), nums.end(), 1);

        if(cnt > 0)
            return n - cnt;
        
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            int GCD = nums[i];

            for(int j = i + 1; j < n; j++) {
                GCD = gcd(GCD, nums[j]);
                if(GCD == 1) {
                    ans = min(ans, j - i + n - 1);
                    break;
                }
            }

            if(GCD != 1)
                break;
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};
