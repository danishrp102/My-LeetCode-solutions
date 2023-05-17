// Problem link: https://leetcode.com/problems/power-of-heroes/description/

class Solution {
private:
    const int mod = 1e9 + 7;

    long long mul(long long x, long long y) {
        long long res = (x % mod) * (y % mod);
        return (res >= mod ? res - mod : res);
    }
    
public:
    int sumOfPower(vector<int>& nums) {
        int n = nums.size(), ans = 0, sum = 0;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++) {
            ans = (ans + mul(sum + nums[i], mul(nums[i], nums[i]))) % mod;
            sum = ((sum * 2) % mod + nums[i]) % mod;
        }

        return ans;
    }
};
