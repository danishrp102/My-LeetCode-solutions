// Problem link: https://leetcode.com/problems/find-the-substring-with-maximum-cost/description/

class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector <int> v(26, -2000);
        int N = chars.size(), maxi = INT_MIN, ans = 0, n = s.size();
        
        for(int i = 0; i < N; i++)
            v[chars[i] - 'a'] = vals[i];
        
        for(int i = 0; i < n; i++) {
            
            int val = s[i] - 'a';
            ans += (v[val] != -2000) ? v[val] : val + 1;
            
            if(ans > maxi)
                maxi = ans;

            if(ans < 0)
                ans = 0;
        }

        return max(maxi, 0);
    }
};
