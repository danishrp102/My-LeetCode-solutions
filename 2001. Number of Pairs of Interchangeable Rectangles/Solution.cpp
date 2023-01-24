// Problem link: https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/description/

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        map <double, long long> mp;

        for(int i = 0; i < n; i++) {
            double val = (double)rectangles[i][0] / (double)rectangles[i][1];
            mp[val]++;
        }

        long long ans = 0;
        for(auto [x, y]: mp) {
            ans += y * (y - 1) / 2;
        }

        return ans;
    }
};
