// Problem link: https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/description/

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end());
        int ans = k * (2 * maxi + k - 1) / 2;
        return ans;
    }
};
