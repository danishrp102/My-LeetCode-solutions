// Problem link: https://leetcode.com/problems/shortest-palindrome/description/

class Solution {
public:

    void solve(vector <int> &lps, int n, string &S) {
        int i = 1, len = 0;

        while(i < n) {
            if(S[i] == S[len])
                lps[i++] = ++len;
            
            else if(len > 0)
                len = lps[len - 1];
            else
                lps[i++] = 0;
        }
    }

    string shortestPalindrome(string s) {
        string str = s;
        reverse(str.begin(), str.end());
        string S = s + "$" + str;
        int n = S.size();

        vector <int> lps(n, 0);
        solve(lps, n, S);

        int val = lps[n - 1];
        string tmp = s.substr(val);
        reverse(tmp.begin(), tmp.end());

        string ans = tmp + s;
        return ans;
    }
};
