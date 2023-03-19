// Problem link: https://leetcode.com/problems/number-of-even-and-odd-bits/

class Solution {
public:
    vector<int> evenOddBit(int n) {
        int val = 0, eve = 0, odd = 0;
        while(n) {
            int x = n & 1;
            if(x) {
                if(val == 0)
                    val = 1, eve++;
                else
                    val = 0, odd++;
            }
            
            else
                val = 1 - val;
            
            n >>= 1;
        }
        
        return {eve, odd};
    }
};
