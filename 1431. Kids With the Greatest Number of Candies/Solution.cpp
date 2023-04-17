// Problem link: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi = *max_element(candies.begin(), candies.end()), n = candies.size();
        vector <bool> ans(n, false);

        for(int i = 0; i < n; i++) {
            if(candies[i] + extraCandies >= maxi)
                ans[i] = true;
        }

        return ans;
    }
};
