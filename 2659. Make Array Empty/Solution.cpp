// Problem link: https://leetcode.com/problems/make-array-empty/description/

class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        unordered_map <int, int> mp;
        int n = nums.size();
        long long ans = n;

        for(int i = 0; i < n; i++)
            mp[nums[i]] = i;
        
        sort(nums.begin(), nums.end());
        for(int i = 1; i < n; i++) {
            if(mp[nums[i]] < mp[nums[i - 1]])
                ans += n - i;
        }

        return ans;
    }
};
