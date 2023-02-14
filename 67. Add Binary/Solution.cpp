// Problem link: https://leetcode.com/problems/add-binary/description/

class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.size(), n2 = b.size();
        if(n2 > n1) {
            swap(n1, n2);
            swap(a, b);
        }

        int carry = 0, j1 = n1 - 1, j2 = n2 - 1;

        for(; j2 >= 0; j2--, j1--) {
            int s = (a[j1] - '0') + (b[j2] - '0') + carry;
            string str = to_string(s % 2);
            a[j1] = str[0];
            carry = s / 2;
        }

        for(int i = j1; i >= 0; i--) {
            
            int s = (a[i] - '0') + carry;
            string str = to_string(s % 2);
            a[i] = str[0];
            carry = s / 2;
            
            j1--;
        }

        if(carry)
            a.insert(0, "1");
        
        return a;
    }
};
