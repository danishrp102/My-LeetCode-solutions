// Problem link: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector <vector <pair <int, bool> > > adj(n);

        for(auto x: connections) {
            adj[x[0]].push_back(make_pair(x[1], true));
            adj[x[1]].push_back(make_pair(x[0], false));
        }

        queue <int> q;
        int ans = 0;
        vector <bool> vis(n, false);
        q.push(0);
        vis[0] = true;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto [x, y]: adj[node]) {
                if(!vis[x]) {
                    q.push(x);
                    vis[x] = true;
                    if(y)
                        ans++;
                }
            }
        }

        return ans;
    }
};
