// Problem link: https://leetcode.com/problems/max-number-of-k-sum-pairs/description/

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map <int, int> mp;
        int i = 0, j = 0;
        int ans = 0, n = nums.size();

        for(auto x: nums)
            mp[x]++;

        for(auto x: nums) {
            if(mp[x] && mp[k - x]) {
                if(x == k - x && mp[x] <= 1) {
                    continue;
                }

                mp[x]--;
                mp[k - x]--;
                ans++;
            }
        }

        return ans;
    }
};
