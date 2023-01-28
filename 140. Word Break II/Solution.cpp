// Problem link: https://leetcode.com/problems/word-break-ii/description/

/*
Intuition

The first observation to make out from the given description is that this problem involves the concept of subproblem within a problem - i.e. DP; meaning, the problem can be broken down into smaller fractions and the final answer can be found by combining the answers to these subproblems.

Approach

We will first insert the list of words into an unordered set (unsorted) so that finding the strings within the set takes negligible time.

Next, we declare an array of array of strings (2D vector) of size one more than the size of the given original string. This two-dimensional array of strings stores in each index 'i' the list of strings that upon concatenation result in a prefix string of length 'i'.

Now we iterate from index i = 0 to the size of the string and for each 'i', from j = i + 1 to the end of the string and check if the resultant substring from position 'i' of length 'j - i' is contained in the list of words in wordDict.

If it is contained in the list of words, the from index 'i', we obtain all the strings that lead up to the prefix string of length 'i' and we append the string of length 'j - i' and push the list in the position 'j' (dp[j]).

The final answer is obtained at the last position of the dp array.

*/

class Solution {
public:

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set <string> st;

        for(auto x: wordDict)
            st.insert(x);
        
        int n = s.size();
        vector <vector <string> > dp(n + 1);
        dp[0] = {""};

        for(int i = 0; i < n; i++) {
            if(dp[i].size() == 0)
                continue;
            
            for(int j = i + 1; j <= n; j++) {
                string tmp = s.substr(i, j - i);

                if(st.count(tmp)) {
                    for(auto x: dp[i]) {
                        string str = x;
                        str += tmp;
                        str.push_back(' ');
                        dp[j].push_back(str);
                    }
                }
            }
        }

        for(auto &x: dp[n])
            x.pop_back();
        
        return dp[n];
    }
};
