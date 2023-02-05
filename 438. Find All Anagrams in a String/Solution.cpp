// Problem link: https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector <int> ans, v(26);

        for(auto x: p)
            v[x - 'a']++;
        
        int n1 = s.size(), n2 = p.size();

        for(int i = 0; i < n1 - n2 + 1; i++) {

            if(v[s[i] - 'a']) {
                vector <int> tmp = v;
                bool f = true;

                for(int j = i; j < i + n2; j++) {
                    if(tmp[s[j] - 'a'])
                        tmp[s[j] - 'a']--;
                    else {
                        f = false;
                        break;
                    }
                }

                if(f)
                    ans.push_back(i);
            }
        }

        return ans;
    }
};
