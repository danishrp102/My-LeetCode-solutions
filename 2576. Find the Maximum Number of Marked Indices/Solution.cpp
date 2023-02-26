// Problem link: https://leetcode.com/problems/find-the-maximum-number-of-marked-indices/description/

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), i = 0;
        int mid = (n + 1) / 2;

        for(int j = mid; j < n; j++) {
            if(nums[i] * 2 <= nums[j])
                i++;
        }

        return i * 2;
    }
};
