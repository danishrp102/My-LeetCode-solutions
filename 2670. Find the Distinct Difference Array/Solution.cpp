// Problem link: https://leetcode.com/problems/find-the-distinct-difference-array/description/

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map <int, int> mp1, mp2;
        vector <int> pref(n, 0), ans(n, 0), suf(n + 1, 0);
        
        for(int i = 0; i < n; i++) {
            mp1[nums[i]]++;
            pref[i] = mp1.size();
        }
        
        for(int i = n - 1; i >= 0; i--) {
            mp2[nums[i]]++;
            suf[i] = mp2.size();
        }
        
        for(int i = 0; i < n; i++)
            ans[i] = pref[i] - suf[i + 1];
    
        return ans;
    }
};
