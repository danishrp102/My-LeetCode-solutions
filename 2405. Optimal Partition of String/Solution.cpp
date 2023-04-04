// Problem link: https://leetcode.com/problems/optimal-partition-of-string/description/

class Solution {
public:
    int partitionString(string s) {
        unordered_map <char, int> mp;
        int ans = 0;

        for(auto x: s) {

            if(mp[x] == 1) {
                ans++;
                mp.clear();
            }

            mp[x]++;
        }

        if(!mp.empty())
            ans++;
        
        return ans;
    }
};
