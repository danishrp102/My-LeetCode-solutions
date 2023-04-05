// Problem link: https://leetcode.com/problems/minimize-maximum-of-array/description/

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        long long sum = 0;
        
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            int tmp = (sum + i) / (i + 1);
            ans = max(ans, tmp);
        }

        return ans;
    }
};
