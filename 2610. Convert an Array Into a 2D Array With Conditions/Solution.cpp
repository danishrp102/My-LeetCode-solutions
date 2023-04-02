// Problem link: https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size(), maxi = INT_MIN;
        unordered_map <int, int> mp;
        
        for(auto x: nums) {
            mp[x]++;
            maxi = max(maxi, mp[x]);
        }
        
        vector <vector <int> > ans(maxi);
        
        for(auto [x, y]: mp) {
            for(int i = 0; i < y; i++)
                ans[i].push_back(x);
        }
        
        return ans;
    }
};
