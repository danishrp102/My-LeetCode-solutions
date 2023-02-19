// Problem link: https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0/description/

class Solution {
public:
    int minOperations(int n) {
        int ans = 0, ones = 0;
        if((n & (n - 1)) == 0)
            return 1;

        for(int i = 0; (1 << i) < n; i++) {
            if((1 << i) & n)
                ones++;
            else {
                if(ones == 1)
                    ans++, ones = 0;
                else if(ones >= 2)
                    ans++, ones = 1;
            }
        }

        if(ones == 1)
            ans++;
        else if(ones >= 2)
            ans += 2;
        
        return ans;
    }
};
