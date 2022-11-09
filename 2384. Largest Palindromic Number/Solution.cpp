class Solution {
public:
    string largestPalindromic(string num) {
        vector <int> v(10, 0);
        vector <bool> odd(10, false);
        int n = num.size();
        for(int i = 0; i < n; i++)
            v[num[i] - '0']++;

        string ans;
        stack <pair <int, int> > st;
        for(int i = 9; i >= 0; i--) {
            int val = v[i] / 2, rem = v[i] % 2;
            st.push({i, val});
            if(rem)
                odd[i] = true;
            ans.append(val, '0' + i);
        }

        if(!ans.empty() && ans[0] == '0') {
            string s;
            for(int i = 9; i >= 0; i--) {
                if(odd[i]) {
                    s.push_back('0' + i);
                    return s;
                }
            }

            return "0";
        }

        for(int i = 9; i >= 0; i--) {
            if(odd[i]) {
                ans.push_back('0' + i);
                break;
            }
        }

        while(!st.empty()) {
            auto [u, v] = st.top();
            st.pop();
            ans.append(v, '0' + u);
        }

        return ans;

    }
};
