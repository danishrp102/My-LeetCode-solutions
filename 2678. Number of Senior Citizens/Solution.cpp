// Problem link: https://leetcode.com/problems/number-of-senior-citizens/description/

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(auto &x: details) {
            int age = (x[11] - '0') * 10 + (x[12] - '0');
            if(age > 60)
                ans++;
        }
        
        return ans;
    }
};
