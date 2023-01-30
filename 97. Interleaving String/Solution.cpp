// Problem link: https://leetcode.com/problems/interleaving-string/description/

class Solution {
public:

    bool solve(string &a, string &b, string &str, int n1, int n2, int n3, int flag, vector <vector <int> > &dp) {
        
        if(n1 == 0 && n2 == 0 && n3 == 0)
            return true;

        if((flag == 1 && n1 == 0) || (flag == 0 && n2 == 0))
            return false;
        
        if(dp[n3][flag] != -1)
            return dp[n3][flag];
        
        bool yes = false;
        
        if(flag) {

            flag = 1 - flag;
            for(int i = n1 - 1; i >= 0; i--) {
                string tmp = a.substr(i, n1 - i);
                if(tmp == str.substr(n3 - n1 + i, n1 - i)) {
                    yes |= solve(a, b, str, i, n2, n3 - n1 + i, flag, dp);
                }
            }
        }

        else {
            
            flag = 1 - flag;
            for(int i = n2 - 1; i >= 0; i--) {
                string tmp = b.substr(i, n2 - i);
                if(tmp == str.substr(n3 - n2 + i, n2 - i)) {
                    yes |= solve(a, b, str, n1, i, n3 - n2 + i, flag, dp);
                }
            }
        }

        return dp[n3][1 - flag] = yes;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if(n3 != n1 + n2)
            return false;

        vector <vector <int> > dp(n3 + 1, {-1, -1});

        return (solve(s1, s2, s3, n1, n2, n3, 0, dp) | solve(s1, s2, s3, n1, n2, n3, 1, dp));
    }
};
