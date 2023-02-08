// Problem link: https://leetcode.com/problems/longest-consecutive-sequence/description/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_map <int, int> mp;
        sort(nums.begin(), nums.end());
        int maxi = 0;

        for(auto x: nums) {
            int val = 0;
            if(mp.find(x - 1) != mp.end()) {
                val = mp[x - 1];
                mp.erase(x);
            }

            mp[x] = val + 1;
            maxi = max(maxi, mp[x]);
        }

        return maxi;
    }
};
