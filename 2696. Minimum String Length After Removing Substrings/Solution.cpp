// Problem link: https://leetcode.com/problems/minimum-string-length-after-removing-substrings/description/

class Solution {
public:
    int minLength(string s) {
        stack <char> st;
        int n = s.size();

        for(int i = 0; i < n; i++) {
            
            if(!st.empty() && ((s[i] == 'D' && st.top() == 'C') || (s[i] == 'B' && st.top() == 'A')))
                st.pop();
            
            else
                st.push(s[i]);
        }

        return st.size();
    }
};
