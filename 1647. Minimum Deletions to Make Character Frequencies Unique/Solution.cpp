// Problem Link: https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/description/

class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        vector <int> v(26, 0);
        for(int i = 0; i < n; i++)
            v[s[i] - 'a']++;
        
        int maxi = *max_element(v.begin(), v.end());
        map <int, int> mp;
        for(int i = 0; i < 26; i++)
            if(v[i] > 0)
                mp[v[i]]++;
        
        vector <int> vis(maxi + 1, false);

        int ans = 0;
        for(auto [x, y]: mp) {
            vis[x] = true;
            y--;
            while(y--) {
                int i;
                for(i = x - 1; i >= 0; i--) {
                    if(!vis[i]) {
                        vis[i] = true;
                        ans += x - i;
                        break;
                    }
                }

                if(i == 0)
                    vis[0] = false;
            }
        }

        return ans;
    }
};
