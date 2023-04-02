// Problem link: https://leetcode.com/problems/shortest-cycle-in-a-graph/description/

class Solution {
public:

    void solve(vector <vector <int> > &adj, vector <int> &time, int t, int node, int par, int &ans) {
        if(time[node] != -1) {
            if(t - time[node] > 0)
                ans = min(ans, t - time[node]);
            return;
        }

        time[node] = t;

        for(auto x: adj[node]) {
            if(x == par)
                continue;
            
            solve(adj, time, t + 1, x, node, ans);
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
            vector <int> time(n, -1);
            solve(adj, time, 0, i, -1, ans);
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};
