// Problem link: https://leetcode.com/problems/determine-if-two-strings-are-close/description/

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector <int> cnt1(26, 0), cnt2(26, 0);
        set <char> s1, s2;

        for(char x: word1)
            cnt1[x - 'a']++, s1.insert(x);
        
        for(char x: word2)
            cnt2[x - 'a']++, s2.insert(x);
        
        sort(cnt1.begin(), cnt1.end());
        sort(cnt2.begin(), cnt2.end());

        return (s1 == s2 && cnt1 == cnt2);
    }
};
