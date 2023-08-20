// Problem link: https://leetcode.com/problems/find-the-longest-equal-subarray/

class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size(), maxi = 0;
        map <int, vector <int> > mp;

        for(int i = 0; i < n; i++)
            mp[nums[i]].push_back(i);
        
        for(auto [x, y]: mp) {
            int m = y.size();
            int i = 0, j = 0;

            while(j < m) {
                if(y[j] - y[i] - (j - i) <= k) {
                    maxi = max(maxi, j - i + 1);
                    j++;
                }

                else {
                    while(y[j] - y[i] - (j - i) > k)
                        i++;
                    
                    maxi = max(maxi, j - i + 1);
                    j++;
                }
            }
        }

        return maxi;
    }
};
