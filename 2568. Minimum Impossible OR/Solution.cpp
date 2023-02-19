// Problem link: https://leetcode.com/problems/minimum-impossible-or/description/

class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        vector <int> v(32, 0);
        
        for(auto x: nums) {
            if((x & (x - 1)) == 0)
                v[log2(x)]++;
        }
        
        for(int i = 0; i < 32; i++) {
            if(v[i] == 0)
                return pow(2, i);
        }

        return -1;
    }
};
