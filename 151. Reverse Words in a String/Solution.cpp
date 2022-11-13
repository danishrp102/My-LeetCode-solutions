// collect all the characters bounded by two pointers: i & j and store the resultant string in a vector
// if a space is encountered, ignore it
// traverse the vector of strings from the end and append each string followed by a space character
// remove the last space character and return the string

class Solution {
public:
    string reverseWords(string s) {
        vector <string> v;
        int n = s.size(), i = 0, j = 0;
        string ans;
        while(i < n) {

            while(j != n && s[j] != ' ')
                j++;
            
            if(j != i)
                v.push_back(s.substr(i, j - i));
            
            i = j + 1;
            j = i;
        }

        for(int i = v.size() - 1; i >= 0; i--) {
            ans += v[i];
            ans.push_back(' ');
        }

        ans.pop_back();
        return ans;
    }
};
