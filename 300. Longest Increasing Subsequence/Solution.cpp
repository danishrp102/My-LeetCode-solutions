// Problem link: https://leetcode.com/problems/longest-increasing-subsequence/description/

// Sol1: DP

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp(n, 1);

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

// Sol2: Binary Search

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector <int> v;

        for(auto x: nums) {
            if(v.empty() || v.back() < x)
                v.push_back(x);
            else {
                auto it = lower_bound(v.begin(), v.end(), x);
                *it = x;
            }
        }

        return v.size();
    }
};
