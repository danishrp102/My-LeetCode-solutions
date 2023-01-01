// Problem link: https://leetcode.com/problems/word-pattern/description/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector <string> v;
        int n = s.size(), i = 0, j = 0;

        while(i < n) {
            if(s[i] == ' ') {
                v.push_back(s.substr(j, i - j));
                j = i + 1;
            }

            i++;
        }

        v.push_back(s.substr(j, i - j));

        map <char, string> mp;
        map <string, char> mp1;
        vector <bool> vis(26, false);
        if(pattern.size() != v.size())
            return false;

        for(int i = 0; i < pattern.size(); i++) {
            if(vis[pattern[i] - 'a']) {
                if(mp[pattern[i]] != v[i] || mp1[v[i]] != pattern[i])
                    return false;
            }

            else {
                if(mp1[v[i]] >= 'a' && mp1[v[i]] <= 'z')
                    return false;

                mp[pattern[i]] = v[i], vis[pattern[i] - 'a'] = true, mp1[v[i]] = pattern[i];
            }

        }

        return true;
    }
};
