// Problem link: https://leetcode.com/problems/shortest-cycle-in-a-graph/description/

class Solution {
public:

    void solve(vector <vector <int> > &adj, int i, vector <int> &dist, vector <int> &par, int &ans) {
        queue <int> q;
        q.push(i);
        dist[i] = 0;

        while(!q.empty()) {

            int node = q.front();
            q.pop();
            
            for(auto x: adj[node]) {
                
                if(dist[x] == INT_MAX) {
                    dist[x] = 1 + dist[node];
                    q.push(x);
                    par[x] = node;
                }

                else if(par[x] != node && par[node] != x)
                    ans = min(ans, dist[x] + dist[node] + 1);
            }
        }
    }

    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector <vector <int> > adj(n);

        for(auto x: edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        int ans = INT_MAX;

        for(int i = 0; i < n; i++) {  
            vector <int> dist(n, INT_MAX), par(n, -1);
            solve(adj, i, dist, par, ans);
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};
