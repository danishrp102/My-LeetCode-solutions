// Problem link: https://leetcode.com/problems/minimum-window-substring/description/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map <char, int> mp;
        for(char &x: t)
            mp[x]++;
        
        int count = mp.size(), i = 0, j = 0, pos = -1, mini = INT_MAX, n = s.size();

        while(j < n) {
            if(mp.find(s[j]) != mp.end()) {
                mp[s[j]]--;
                if(mp[s[j]] == 0)
                    count--;
            }

            if(count > 0)
                j++;

            if(count == 0) {
                while(count == 0) {
                    if(j - i + 1 < mini) {
                        mini = j - i + 1;
                        pos = i;
                    }

                    if(mp.find(s[i]) != mp.end()) {
                        mp[s[i]]++;
                        if(mp[s[i]] == 1)
                            count++;
                    }

                    i++;
                }

                j++;
            }
        }

        if(pos == -1)
            return "";
        
        string ans = s.substr(pos, mini);
        return ans;
    }
};
