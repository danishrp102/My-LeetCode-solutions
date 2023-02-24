// Problem link: https://leetcode.com/problems/subarrays-with-k-different-integers/description/

class Solution {
public:

    int solve(vector <int> &nums, int &n, int k) {
        int i = 0, j = 0, ans = 0;
        unordered_map <int, int> mp;

        while(j < n) {
            mp[nums[j]]++;

            while(mp.size() > k) {
                mp[nums[i]]--;
                if(mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }

            ans += (j - i + 1);
            j++;
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int ans1 = solve(nums, n, k);
        int ans2 = solve(nums, n, k - 1);

        return (ans1 - ans2);
    }
};
