// Problem link: https://leetcode.com/problems/count-total-number-of-colored-cells/description/

class Solution {
public:
    
    long long coloredCells(int n) {
        long long ans = 1ll;
        
        for(int i = 2; i <= n; i++)
            ans = (ans + (i - 1) * 4);
        
        return ans;
    }
};
