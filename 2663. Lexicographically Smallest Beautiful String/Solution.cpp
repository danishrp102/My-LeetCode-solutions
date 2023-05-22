// Problem link: https://leetcode.com/problems/lexicographically-smallest-beautiful-string/description/

class Solution {
private:
    bool check(string &s, int i) {
        return ((i < 1 || s[i] != s[i - 1]) && (i < 2 || s[i] != s[i - 2]));
    }

public:
    string smallestBeautifulString(string s, int k) {
        int n = s.size();

        for(int i = n - 1; i >= 0; i--) {
            
            do {
                s[i]++;
            } while(!check(s, i));
        
            if(s[i] < 'a' + k) {
                for(int j = i + 1; j < n; j++)
                    for(s[j] = 'a'; !check(s, j); s[j]++);
                
                return s;
            }
        }

        return "";
    }
};
