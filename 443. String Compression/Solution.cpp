// Problem link: https://leetcode.com/problems/string-compression/description/

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), ans = 0, i = 0, j = 1, ind = 0;
        while(j < n) {
            if(chars[j - 1] != chars[j]) {
                if(j - i == 1)
                    ans++, chars[ind++] = chars[i++];

                else {
                    chars[ind++] = chars[i];
                    int num = j - i;
                    stack <char> s;
                    while(num) {
                        s.push('0' + (num % 10));
                        num /= 10;
                    }

                    ans += s.size() + 1;
                    while(!s.empty()) {
                        chars[ind++] = s.top();
                        s.pop();
                    }

                    i = j;
                }
            }

            j++;
        }

        if(j - i == 1)
            chars[ind++] = chars[i++], ans++;
        else {
            chars[ind++] = chars[i];
            int num = j - i;
            stack <char> s;
            while(num) {
                s.push('0' + (num % 10));
                num /= 10;
            }

            ans += s.size() + 1;
            while(!s.empty()) {
                chars[ind++] = s.top();
                s.pop();
            }   
        }

        return ans;
    }
};
