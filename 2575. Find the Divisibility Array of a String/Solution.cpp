// Problem link: https://leetcode.com/problems/find-the-divisibility-array-of-a-string/description/

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        unsigned long long int num = 0ll;
        int n = word.size();
        vector <int> ans(n, 0);
        
        for(int i = 0; i < n; i++) {
            long long int v = (word[i] - '0');
            num *= 10ll;
            num += v;
        
            if(num % m == 0)
                ans[i] = 1;
        
            num %= m;
        }
        
        return ans;
    }
};
