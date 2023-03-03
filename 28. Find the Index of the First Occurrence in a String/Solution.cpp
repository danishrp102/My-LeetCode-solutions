// Problem link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();

        if(n > m)
            return -1;
            
        for(int i = 0; i <= m - n; i++) {
            string tmp = haystack.substr(i, n);
            if(tmp == needle)
                return i;
        }

        return -1;
    }
};
