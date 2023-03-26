// Problem link: https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal/description/

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), N = queries.size();
        sort(nums.begin(), nums.end());
        
        vector <long long> pref(n), v(N);
        pref[0] = nums[0];
        
        for(int i = 1; i < n; i++)
            pref[i] = (pref[i - 1] + nums[i]) * 1ll;
        
        for(int i = 0; i < N; i++) {
            long long pos = upper_bound(nums.begin(), nums.end(), queries[i]) - nums.begin();
            if(pos == 0) {
                v[i] = pref[n - 1] - queries[i] * 1ll * n; 
                continue;
            }
            
            v[i] = pos * 1ll * queries[i] - pref[pos - 1];
            v[i] += (pref[n - 1] - pref[pos - 1]) - (n - pos) * 1ll * queries[i];
            
            // v[i] += (pref[n - 1] - 2 * pref[pos - 1]) + (2 * pos - n) * queries[i] * 1ll;
        }
        
        return v;
    }
};
