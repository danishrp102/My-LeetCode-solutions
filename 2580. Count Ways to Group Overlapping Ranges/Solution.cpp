// Problem link: https://leetcode.com/problems/count-ways-to-group-overlapping-ranges/description/

class Solution {
public:
    
    const int mod = 1e9 + 7;
    
    int countWays(vector<vector<int>>& ranges) {
        int n = ranges.size(), ans = 0;
        sort(ranges.begin(), ranges.end());
        
        int i = 0, j = 1, maxi = ranges[0][1];
        while(j < n) {
            
            if(ranges[j][0] <= maxi)
                maxi = max(maxi, ranges[j][1]);
            
            else {
                ans++;
                i = j;
                maxi = ranges[i][1];
            }

            j++;
        }
        
        ans++;
        
        long long int final = 1, x = 2;
        while(ans) {
            if(ans & 1)
                final = (final * x) % mod;
            
            ans >>= 1;
            x = (x * x) % mod;
        }
        
        return final;
    }
};
