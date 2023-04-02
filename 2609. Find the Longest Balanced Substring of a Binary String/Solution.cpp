// Problem link: https://leetcode.com/problems/find-the-longest-balanced-substring-of-a-binary-string/description/

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int n = s.size();
        vector <int> pref(n + 1, 0);
        
        for(int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1];
            if(s[i - 1] == '1')
                pref[i]++;
        }
        
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 2; i + j - 1 <= n; j += 2) {
                if(pref[i + j - 1] - pref[i - 1] == j / 2 && pref[i + (j / 2) - 1] - pref[i - 1] == 0)
                    ans = max(ans, j);
            }
        }
        
        return ans;
    }
};
