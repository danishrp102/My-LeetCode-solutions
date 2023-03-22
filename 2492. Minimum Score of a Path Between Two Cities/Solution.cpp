// Problem link: https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector <vector <pair <int, int> > > adj(n);

        for(auto x: roads) {
            adj[x[0] - 1].push_back(make_pair(x[1] - 1, x[2]));
            adj[x[1] - 1].push_back(make_pair(x[0] - 1, x[2]));
        }

        int ans = INT_MAX;
        vector <bool> vis(n, false);
        queue <int> q;
        q.push(0);
        vis[0] = true;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto [x, y]: adj[node]) {
                if(!vis[x]) {
                    q.push(x);
                    vis[x] = true;

                    for(auto [m, n]: adj[x])
                        ans = min(ans, n);
                }
            }
        }

        return ans;
    }
};
