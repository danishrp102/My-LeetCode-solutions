// Problem link: https://leetcode.com/problems/single-element-in-a-sorted-array/description/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(), low = 0, high = n - 1, mid;

        while(low < high) {
            mid = low + (high - low) / 2;
            
            if(nums[mid] == nums[mid ^ 1])
                low = mid + 1;
            else
                high = mid;
        }

        return nums[low];
    }
};
