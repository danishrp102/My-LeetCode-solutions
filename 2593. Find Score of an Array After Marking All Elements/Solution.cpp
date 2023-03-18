// Problem link: https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/description/

class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans = 0;
        priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq;
        int n = nums.size();

        for(int i = 0; i < n; i++)
            pq.push(make_pair(nums[i], i));
        
        vector <bool> vis(n, false);

        while(!pq.empty()) {
            auto [val, ind] = pq.top();
            pq.pop();

            if(!vis[ind]) {
                 vis[ind] = true;
                 ans += val;
                 
                if(ind != 0)
                    vis[ind - 1] = true;
                if(ind != n - 1)
                    vis[ind + 1] = true;
            }
        }

        return ans;
    }
};
