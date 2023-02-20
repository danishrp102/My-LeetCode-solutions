// Problem link: https://leetcode.com/problems/subarray-sum-equals-k/description/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, ans = 0;
        unordered_map <int, int> mp;

        for(int i = 0; i < n; i++) {
            sum += nums[i];

            if(sum == k)
                ans++;
            
            if(mp.find(sum - k) != mp.end())
                ans += mp[sum - k];
            mp[sum]++;
        }

        return ans;
    }
};
