// Problem link: https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int j = 0, i, n = nums.size();
        long long ans = 0ll, sum = 0ll;
        unordered_map <int, int> mp;

        for(i = 0; i < k; i++) {
            mp[nums[i]]++;
            sum += nums[i];
        }

        while(i < n) {
            if(mp.size() == k)
                ans = max(ans, sum);

            cout << mp.size() << "\n";
            
            mp[nums[j]]--;
            mp[nums[i]]++;

            if(mp[nums[j]] == 0)
                mp.erase(nums[j]);

            sum -= nums[j++];
            sum += nums[i++];
        }

        if(mp.size() == k)
            ans = max(ans, sum);

        return ans;
    }
};
