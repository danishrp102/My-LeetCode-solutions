// Problem link: https://leetcode.com/problems/find-the-score-of-all-prefixes-of-an-array/description/

class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size(), maxi;
        vector <long long> ans(n);
        maxi = nums[0];
        ans[0] = 2 * nums[0];
        
        for(int i = 1; i < n; i++) {
            maxi = max(maxi, nums[i]);
            ans[i] = nums[i] + maxi;
            ans[i] += ans[i - 1];
        }
        
        return ans;
    }
};
