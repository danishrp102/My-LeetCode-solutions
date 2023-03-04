// Problem link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

// Brute force
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

// KMP Algorithm
class Solution {
public:

    void solve(vector <int>& lps, int n, string &str) {
        int i = 1, len = 0;
        while(i < n) {
            if(str[i] == str[len])
                lps[i++] = ++len;
            
            else if(len)
                len = lps[len - 1];
            else
                lps[i++] = 0;
        }
    }

    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        vector <int> lps(n, 0);
        solve(lps, n, needle);

        int i = 0, j = 0;
        while(i < m) {
            if(haystack[i] == needle[j])
                i++, j++;
            
            if(j == n)
                return i - j;
            
            if(i < m && haystack[i] != needle[j])
                (j > 0) ? j = lps[j - 1] : i++;
        }

        return -1;
    }
};
