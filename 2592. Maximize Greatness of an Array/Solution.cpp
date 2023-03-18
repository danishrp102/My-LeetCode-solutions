// Problem link: https://leetcode.com/problems/maximize-greatness-of-an-array/description/

class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int n = nums.size();
        map <int, int> mp;
        for(int i = 0; i < n; i++)
            mp[nums[i]]++;
        
        vector <int> v1, v2;
        for(auto [x, y]: mp) {
            v1.push_back(x);
            v2.push_back(y);
        }
        
        int N = v1.size(), ans = 0;
        
        for(int i = 0; i < n; i++) {
            auto it = upper_bound(v1.begin(), v1.end(), nums[i]) - v1.begin();
            if(it == N)
                continue;
            
            for(int j = it; j < N; j++) {
                if(v2[j] > 0) {
                    ans++;
                    v2[j]--;
                    break;
                }
            }
        }
        
        return ans;
    }
};
