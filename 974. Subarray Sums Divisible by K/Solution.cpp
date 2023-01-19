// Problem link: https://leetcode.com/problems/subarray-sums-divisible-by-k/description/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector <int> pref(n + 1, 0);
        unordered_map <int, int> mp;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            pref[i + 1] = ((pref[i] + nums[i]) % k + k) % k;
            mp[pref[i + 1]]++;
        }
        

        for(auto [x, y]: mp) {
            ans += y * (y - 1) / 2;
        }

        return ans + mp[0];
    }
};
