// Problem link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector <vector <int> > v(3);
        int n = s.size(), ans = 0, p1 = 0, p2 = 0, p3 = 0;

        for(int i = 0; i < n; i++)
            v[s[i] - 'a'].push_back(i);
        
        for(int i = 0; i < n; i++) {
            if(p1 == v[0].size() || p2 == v[1].size() || p3 == v[2].size())
                break;

            int maxi = max({v[0][p1], v[1][p2], v[2][p3]});
            ans += n - maxi;

            if(s[i] == 'a')
                p1++;
            else if(s[i] == 'b')
                p2++;
            else
                p3++;
        }

        return ans;
    }
};
