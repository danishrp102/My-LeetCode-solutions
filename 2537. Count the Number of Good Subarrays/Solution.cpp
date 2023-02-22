// Problem link: https://leetcode.com/problems/count-the-number-of-good-subarrays/description/

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0, i = 0, j = 0, pairs = 0;
        int n = nums.size();
        unordered_map <int, int> mp;

        while(j < n) {
            mp[nums[j]]++;
            pairs += mp[nums[j]] - 1;

            if(pairs < k)
                j++;

            else if(pairs >= k) {
                while(pairs >= k) {
                    ans += n - j;
                    pairs -= mp[nums[i]] - 1;
                    mp[nums[i]]--;
                    i++;
                }

                j++;
            }
        }

        return ans;
    }
};
