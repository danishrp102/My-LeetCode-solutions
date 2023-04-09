// Problem link: https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int l = 0, r = 1e9 + 1, mid;

        while(l < r) {
            mid = l + (r - l) / 2;
            int cnt = 0;

            for(int i = 0; i < n - 1; i++) {
                if(nums[i + 1] - nums[i] <= mid)
                    cnt++, i++;
            }

            if(cnt >= p)
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};
