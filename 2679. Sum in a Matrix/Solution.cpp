// Problem link: https://leetcode.com/problems/sum-in-a-matrix/description/

class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int m = nums.size(), n = nums[0].size();
        
        for(int i = 0; i < m; i++)
            sort(nums[i].begin(), nums[i].end(), greater<int>());
        
        int ans = 0;
        for(int j = 0; j < n; j++) {
            int maxi = INT_MIN;
            for(int i = 0; i < m; i++)
                maxi = max(maxi, nums[i][j]);
            ans += maxi;
        }
        
        return ans;
    }
};
