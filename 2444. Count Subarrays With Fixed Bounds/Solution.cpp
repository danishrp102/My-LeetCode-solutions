// Problem link: https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/

class Solution {
public:

    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        long long jmin = -1, jmax = -1, jbad = -1, i = 0, n = nums.size();

        while(i < n) {
            if(nums[i] < minK || nums[i] > maxK)
                jbad = i;
            if(nums[i] == minK)
                jmin = i;
            if(nums[i] == maxK)
                jmax = i;
            i++;

            ans += max(0LL, min(jmin, jmax) - jbad);
        }

        return ans;
    }
};
