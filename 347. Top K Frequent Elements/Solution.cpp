// Problem link: https://leetcode.com/problems/top-k-frequent-elements/description/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> mp1;
        map <int, vector <int> > mp2;
        vector <int> ans;
        int i = 0;

        for(auto &x: nums)
            mp1[x]++;

        for(auto [x, y]: mp1)
            mp2[y].push_back(x);
        
        for(auto it = mp2.rbegin(); it != mp2.rend() && i < k; it++) {
            int n = it->second.size();
            for(int j = 0; j < n && i < k; i++, j++)
                ans.push_back(it->second[j]);
        }
        
        return ans;
    }
};
