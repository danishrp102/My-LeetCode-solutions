class Solution {
public:
    string removeDuplicates(string s) {
        stack <pair <char, int> > st; // to store characters that are yet to be deleted(possibly)
        st.push({'.', -1}); // initially to check with the first character
  
        int n = s.size();
        vector <bool> pos(n, true); //stores the position to be considered for the final string

        for(int i = 0; i < n; i++) {

            if(st.top().first == s[i]) {
                while(st.top().first == s[i]) {
                    pos[i] = pos[st.top().second] = false; //not considering them in the final answer
                    st.pop();
                }
            }

            else
                st.push({s[i], i}); // may match with the same character in the further iteration
        }
    
        string ans;
        for(int i = 0; i < n; i++)
            if(pos[i])
                ans.push_back(s[i]);

        return ans;
    }
};
