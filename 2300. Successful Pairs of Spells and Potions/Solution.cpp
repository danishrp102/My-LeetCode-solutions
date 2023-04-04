// Problem link: https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector <int> ans;

        for(auto x: spells) {
            long long s = (success + x - 1) / x;
            auto it = lower_bound(potions.begin(), potions.end(), s);
            ans.push_back(potions.end() - it);
        }

        return ans;
    }
};
