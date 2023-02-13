// Problem link: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/description/

class Solution {
public:
    int countOdds(int low, int high) {
        int dif = (high - low);
        return ((dif + 1) / 2) + ((low & 1) && !(dif & 1));
    }
};
