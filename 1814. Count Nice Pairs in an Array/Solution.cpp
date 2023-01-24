// Problem link: https://leetcode.com/problems/count-nice-pairs-in-an-array/description/

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        const long long int mod = 1e9 + 7;

        unordered_map <int, int> mp;

        for(int i = 0; i < n; i++) {
            int N = nums[i], rev = 0;
            
            while(N) {
                rev *= 10;
                rev += N % 10;
                N /= 10;
            }

            mp[nums[i] - rev]++;
        }

        int ans = 0;
        for(auto [x, y]: mp) {
        
            for(int i = 1; i < y; i++) {
                ans = (ans + i) % mod;
            }
        }
        return ans;
    }
};
