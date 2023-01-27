// Problem link: https://leetcode.com/problems/word-break/description/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set <string> st;
        for(auto x: wordDict)
            st.insert(x);

        int n = s.size();
        vector <bool> dp(n + 1, false);
        dp[0] = true;

        for(int i = 0; i < n; i++) {
            if(!dp[i])
                continue;
            
            for(int j = i + 1; j <= n; j++) {
                if(st.count(s.substr(i, j - i)))
                    dp[j] = true;
            }

            if(dp[n])
                return true;
        }

        return false;
    }
};
