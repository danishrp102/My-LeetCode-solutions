// Problem link: https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        int i = 0, j = 0;
        
        while(i < m && j < n) {
            char ch = str2[j];
            if(str2[j] == 'a')
                ch = 'z';
            else
                ch--;
            
            if(str1[i] == str2[j] || str1[i] == ch)
                i++, j++;
            else
                i++;
        }
        
        if(j == n)
            return true;
        else
            return false;
    }
};
