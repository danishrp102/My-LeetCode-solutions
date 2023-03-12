// Problem link: https://leetcode.com/problems/count-the-number-of-beautiful-subarrays/description/

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long ans = 0;
        unordered_map <int, int> mp{{0, 1}};

        int n = nums.size(), XOR = 0;
        for(int i = 0; i < n; i++) {
            XOR ^= nums[i];
            ans += mp[XOR];
            mp[XOR]++;
        }

        return ans;
    }
};
