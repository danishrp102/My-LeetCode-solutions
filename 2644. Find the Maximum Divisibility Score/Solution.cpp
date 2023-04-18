// Problem link: https://leetcode.com/problems/find-the-maximum-divisibility-score/description/

class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        set <int> s;
        int m = nums.size(), n = divisors.size();
        unordered_map <int, int> mp;
        for(int i = 0; i < m; i++)
            mp[nums[i]]++;
        
        
        for(int i = 0; i < n; i++)
            s.insert(divisors[i]);
        
        int maxi = INT_MIN, ans = 0;
        
        for(auto x: s) {
            
            int val = 0;
            
            for(auto [y, z]: mp) {
                if(y % x == 0)
                    val += z;
            }
            
            if(val > maxi) {
                maxi = val;
                ans = x;
            }
        }
        
        return ans;
     }
};
