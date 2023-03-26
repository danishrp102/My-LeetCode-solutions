// Problem link: https://leetcode.com/problems/k-items-with-the-maximum-sum/description/

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if(k <= numOnes)
            return k;
        else {
            k -= numOnes;
            if(k <= numZeros)
                return numOnes;
            else {
                k -= numZeros;
                return numOnes - k;
            }
        }
    }
};
