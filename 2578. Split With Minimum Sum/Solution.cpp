// Problem Link: https://leetcode.com/problems/split-with-minimum-sum/

class Solution {
public:
    int splitNum(int num) {
        map <int, int> mp;
        int x = num;
        while(x) {
            mp[x % 10]++;
            x /= 10;
        }
        
        int n1 = 0, n2 = 0;
        bool flag = false;
        for(auto [x, y]: mp) {
            int tmp = y;
            
            while(tmp) {
                if(flag)
                    n2 *= 10, n2 += x, flag = false;
                else
                    n1 *= 10, n1 += x, flag = true;
                tmp--;
            }
        }
        
        return n1 + n2;
    }
};
