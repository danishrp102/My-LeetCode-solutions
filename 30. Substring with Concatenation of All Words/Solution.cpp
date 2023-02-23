// Problem link: https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        int n = s.size(), m = words[0].size(), N = words.size();
        vector <int> ans;

        for(int k = 0; k < m; k++) {

            unordered_map <string, int> mp;
            for(string &x: words)
                mp[x]++;
            
            int count = mp.size(), i = k, j = k;

            while(j < n + 1) {
            
                string tmp = s.substr(j, m);

                if(j - i < (N * m)) {
                    if(mp.find(tmp) != mp.end()) {
                        mp[tmp]--;
                        if(mp[tmp] == 0)
                            count--;
                    }   
                    
                    j += m; 
                }

                else if(j - i == (N * m)) {

                    if(count == 0)
                        ans.push_back(i);
                    
                    string str = s.substr(i, m);
                    if(mp.find(str) != mp.end()) {
                        mp[str]++;
                        if(mp[str] == 1)
                            count++;
                    }
                    
                    if(mp.find(tmp) != mp.end()) {
                        mp[tmp]--;
                        if(mp[tmp] == 0)
                            count--;
                    }
                    
                    j += m, i += m;
                }
            }
        }

        return ans;
    }
};
