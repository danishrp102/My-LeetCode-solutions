// Problem link: https://leetcode.com/problems/determine-the-minimum-sum-of-a-k-avoiding-array/description/

class Solution {
public:
    int minimumSum(int n, int k) {
        int tmp = k / 2;
        int sum = 0, i = 0, s = 1;
        
        while(i < n && s <= tmp) {
            sum += s++;
            i++;
        }

        s = k;
        while(i < n) {
            sum += s++;
            i++;
        }

        return sum;
    }
};
