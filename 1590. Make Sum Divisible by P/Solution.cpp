// Problem link: https://leetcode.com/problems/make-sum-divisible-by-p/description/

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        unordered_map <int, int> mp = {{0, -1}};
        int ans = n, cur = 0, want, rem = 0;
        for(int i = 0; i < n; i++)
            rem = (rem + nums[i]) % p;

        for(int i = 0; i < n; i++) {
            cur = ((cur + nums[i]) % p + p) % p;
            mp[cur] = i;
            want = (cur - rem + p) % p;
            if(mp.count(want))
                ans = min(ans, i - mp[want]);
        }

        return (ans < n) ? ans : -1;
    }
};
