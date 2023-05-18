// Problem link: https://leetcode.com/problems/find-the-losers-of-the-circular-game/description/

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector <bool> vis(n, false);
        vis[0] = true;
        int i = 0, cnt = 1;
        
        while(true) {
            int nxt = (cnt * k) % n;
            cnt++;
            i = (i + nxt) % n;
            
            if(vis[i])
                break;
            else
                vis[i] = true;
        }
        
        vector <int> ans;
        for(int i = 0; i < n; i++)
            if(!vis[i])
                ans.push_back(i + 1);
        
        return ans;
    }
};
