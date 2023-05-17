// Problem link: https://leetcode.com/problems/maximum-or/

class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size(), val = 0;
        vector <int> v(n, 0);
        
        for(int i = n - 2; i >= 0; i--)
            v[i] = v[i + 1] | nums[i + 1];
        
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            long long tmp = val | (nums[i] * 1ll) << k | v[i];
            ans = max(ans, tmp);
            val |= nums[i];
        }
        
        return ans;
    }
};
