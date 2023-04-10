// Problem link: https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
    bool isValid(string s) {
        stack <char> st;

        for(auto x: s) {

            if(x == '(' || x == '{' || x == '[')
                st.push(x);

            else if(x == ')') {
                if(!st.empty() && st.top() == '(')
                    st.pop();
                else
                    return false;
            }

            else if(x == '}') {
                if(!st.empty() && st.top() == '{')
                    st.pop();
                else
                    return false;
            }

            else if(x == ']') {
                if(!st.empty() && st.top() == '[')
                    st.pop();
                else
                    return false;
            }
        }

        return st.empty();
    }
};
