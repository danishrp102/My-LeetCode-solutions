// Problem link: https://leetcode.com/problems/count-number-of-bad-pairs/description/

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans = 0;
        map <long long, long long> mp;
        long long n = nums.size();

        for(long long i = 0; i < n; i++)
            mp[nums[i] - i]++;
        
        for(auto [x, y]: mp) {
            ans += y * (y - 1) / 2;
        }

        return (n * (n - 1) / 2) - ans;
    }
};
