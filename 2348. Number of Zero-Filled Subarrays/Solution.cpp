// Problem link: https://leetcode.com/problems/number-of-zero-filled-subarrays/description/

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();

        long long i = 0, j = 0;
        while(j < n) {
            if(nums[j] == 0)
                j++;
            else {
                ans += (j - i) * (j - i + 1) / 2;
                j++;
                i = j;
            }
        }

        ans += (j - i) * (j - i + 1) / 2;
        return ans;
    }
};
