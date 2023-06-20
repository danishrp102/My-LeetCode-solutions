// Problem link: https://leetcode.com/problems/k-radius-subarray-averages/description/

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size(), i = 0, j = 0;
        long long sum = 0;
        vector <int> ans(n, -1);

        while(j < n) {
            if(j - 2 * k < 0) {
                sum += nums[j];
                j++;
            }

            else {
                sum += nums[j];
                ans[j - k] = sum / (2 * k + 1);
                sum -= nums[i++];
                j++;
            }
        }

        return ans;
    }
};
