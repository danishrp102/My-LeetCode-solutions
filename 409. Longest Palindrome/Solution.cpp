class Solution {
public:
    int longestPalindrome(string s) {
        map <char, int> mp;
        for(auto x: s)
            mp[x]++;
        int ans = 0, tmp;
        bool f = false;
        for(auto [x, y]: mp) {
            if(y & 1)
                f = true, y--;
            ans += y;
        }

        if(f)
            return ans + 1;
        return ans;
    }
};
