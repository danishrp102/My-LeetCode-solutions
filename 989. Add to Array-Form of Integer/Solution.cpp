// Problem link: https://leetcode.com/problems/add-to-array-form-of-integer/description/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector <int> v;
        int carry = 0, n = num.size(), i;

        for(i = n - 1; i >= 0; i--) {

            int s = (k % 10) + num[i] + carry;
            k /= 10;
            v.push_back(s % 10);
            carry = s / 10;
        }

        while(k) {
            int s = (k % 10) + carry;
            k /= 10;
            v.push_back(s % 10);
            carry = s / 10;
        }

        for(int j = i; j >= 0; j--) {
            int s = num[i] + carry;
            v.push_back(s % 10);
            carry = s / 10;
        }

        if(carry)
            v.push_back(carry);
        
        reverse(v.begin(), v.end());
        return v;
    }
};
