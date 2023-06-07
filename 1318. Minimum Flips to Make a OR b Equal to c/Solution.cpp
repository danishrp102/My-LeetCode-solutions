// Problem link: https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;

        while(c) {
            bool stat1 = (a & 1) | (b & 1), stat2 = (a & 1) & (b & 1);
            if((c & 1) == 0)
                ans += stat1 + stat2;
            else if(stat1 == 0)
                ans++;
            
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        while(a || b) {
            ans += (a & 1) + (b & 1);
            a >>= 1;
            b >>= 1;
        }

        return ans;
    }
};
