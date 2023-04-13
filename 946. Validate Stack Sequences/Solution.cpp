// Problem link: https://leetcode.com/problems/validate-stack-sequences/description/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0, j = 0, m = pushed.size(), n = popped.size();
        stack <int> st;

        while(i < m) {
            st.push(pushed[i++]);

            while(j < n && !st.empty() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }

        return (j == n);
    }
};
