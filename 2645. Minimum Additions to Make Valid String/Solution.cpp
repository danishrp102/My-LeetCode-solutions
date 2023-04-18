// Problem link: https://leetcode.com/problems/minimum-additions-to-make-valid-string/description/

// Code 1:

class Solution {
public:
    int addMinimum(string word) {
        int n = word.size(), k = 0;
        char prev = 'z';

        for(int i = 0; i < n; i++) {
            k += (word[i] <= prev);
            prev = word[i];
        }

        int ans = k * 3 - n;
        return ans;
    }
};

// Code 2:

class Solution {
public:
    int addMinimum(string word) {
        int n = word.size(), ans = 0, i = 0;
        
        if(word[0] == 'b')
            ans++;
        else if(word[0] == 'c')
            ans += 2;
        
        while(i < n - 1) {
            if(word[i] == 'a') {
                if(word[i + 1] == 'c')
                    ans++, i++;
                else if(word[i + 1] == 'a')
                    ans += 2, i++;
                else
                    i++;
            }
            
            else if(word[i] == 'b') {
                if(word[i + 1] == 'a')
                    ans++, i++;
                else if(word[i + 1] == 'b')
                    ans += 2, i++;
                else
                    i++;
            }
            
            else {
                if(word[i + 1] == 'b')
                    ans++, i++;
                else if(word[i + 1] == 'c')
                    ans += 2, i++;
                else
                    i++;
            }
        }
        
        if(word[n - 1] == 'b')
            ans++;
        else if(word[n - 1] == 'a')
            ans += 2;
        
        return ans;
    }
};
