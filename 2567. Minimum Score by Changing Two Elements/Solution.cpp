// Problem link: https://leetcode.com/problems/minimum-score-by-changing-two-elements/description/

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 3)
            return 0;
        
        sort(nums.begin(), nums.end());
        
        if(n == 4)
            return min({nums[1] - nums[0], nums[2] - nums[1], nums[3] - nums[2]});
        
        return min({nums[n - 3] - nums[0], nums[n - 1] - nums[2], nums[n - 2] - nums[1]});
    }
};
