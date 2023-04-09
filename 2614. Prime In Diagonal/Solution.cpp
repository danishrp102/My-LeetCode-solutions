// Problem link: https://leetcode.com/problems/prime-in-diagonal/description/

class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++)
            maxi = max(maxi, *max_element(nums[i].begin(), nums[i].end()));
        
        vector <bool> sieve(maxi + 1, true);
        
        for(long long i = 2; i <= maxi; i++) {
            if(sieve[i]) {
                for(long long j = i * i; j <= maxi; j += i)
                    sieve[j] = false;
            }
        }
        
        sieve[0] = sieve[1] = false;
        
        int ans = INT_MIN;
        for(int i = 0; i < n; i++) {
            if(sieve[nums[i][i]])
                ans = max(ans, nums[i][i]);
            if(sieve[nums[i][n - i - 1]])
                ans = max(ans, nums[i][n - i - 1]);
        }
        
        return (ans == INT_MIN) ? 0 : ans;
    }
};
