// Problem link: https://leetcode.com/problems/distribute-money-to-maximum-children/description/

class Solution {
public:
    int distMoney(int money, int children) {
        if(money < children)
            return -1;
        
        money -= children;
        
        int n = money / 7;
        int rem = money % 7;
        if(n >= children) {
            if(rem == 0 && n == children)
                return n;
            else
                return children - 1;
        }

        else {
            if(rem == 3) {
                if(n == 0)
                    return 0;
                else if(children - n >= 2)
                    return n;
                else
                    return n - 1;
            }
            else
                return n;
        }
    }
};
