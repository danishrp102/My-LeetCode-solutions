// check if string obtained from previous iteration is equal to the current iteration or not
// if both the strings are equal, the return the string
// else continue the process till an empty string is achieved

class Solution {
public:
    string makeGood(string s) {
        while(true) {
            string str;
            int i = 0, n = s.size();
            while(i < n - 1) {
                if(abs(s[i] - s[i + 1]) == 32)
                    i += 2;
                else
                    str.push_back(s[i]), i++;
            }

            if(i == n - 1)
                str.push_back(s[i]);

            if(s == str)
                break;
            
            s = str;
            
        }

        return s;
    }
};
