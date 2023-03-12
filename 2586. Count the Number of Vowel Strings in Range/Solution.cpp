// Problem link: https://leetcode.com/problems/count-the-number-of-vowel-strings-in-range/description/

class Solution {
public:
    
    bool isVow(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    
    int vowelStrings(vector<string>& words, int left, int right) {
        int n = words.size();
        int ans = 0;
        for(int i = left; i <= right; i++) {
            if(isVow(words[i].front()) && isVow(words[i].back()))
                ans++;
        }
        
        return ans;
    }
};
