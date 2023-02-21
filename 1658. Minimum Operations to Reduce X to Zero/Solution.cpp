// Problem link: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/description/

//Solution 1 (slow):

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int ans = INT_MAX, n = nums.size(), sum = 0;

        unordered_map <int, int> mp = {{0, n}};

        for(int i = n - 1; i >= 0; i--) {
            sum += nums[i];
            mp[sum] = i;
        }

        if(mp.find(x) != mp.end())
            ans = n - mp[x];

        sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(mp.find(x - sum) != mp.end()) {
                if(i < mp[x - sum])
                    ans = min(ans, i + 1 + (n - mp[x - sum]));
            }
        }

        return (ans == INT_MAX) ? -1: ans;
    }
};

// Solution 2 (faster):

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), i = 0, j = 0;
        int s = accumulate(nums.begin(), nums.end(), 0);

        if(s == x)
            return n;

        int k = s - x;
        int sum = 0, maxi = -1;

        while(j < n) {
            sum += nums[j];

            if(sum > k) {
                while(sum > k && i <= j)
                    sum -= nums[i++];
            }

            if(sum == k) {
                maxi = max(maxi, j - i + 1);
            }

            j++;
        }

        return (maxi == -1) ? -1 : (n - maxi);
    }
};
