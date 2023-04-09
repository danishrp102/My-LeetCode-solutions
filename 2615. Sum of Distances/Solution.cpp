// Problem link: https://leetcode.com/problems/sum-of-distances/description/

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector <long long> ans(n, 0);
        
        unordered_map <int, vector <int> > mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        for(auto [x, v]: mp) {
            int N = v.size();
            vector <long long> pref(N, 0);
            pref[0] = v[0];
            
            for(int i = 1; i < N; i++)
                pref[i] = pref[i - 1] + v[i];
            
            for(int i = 0; i < N; i++) {
                long long res = 0;
                
                if(i != N - 1)
                    res += pref[N - 1] - pref[i] - (N - i - 1) * 1ll * v[i];
                
                if(i != 0)
                    res += i * 1ll * v[i] - pref[i - 1];
                
                ans[v[i]] = res;
            }
        }
        
        return ans;
    }
};
