// Problem link: https://leetcode.com/problems/most-profitable-path-in-a-tree/description/

class Solution {
private:
    void solve(vector <vector <int> > &adj, int node, int p, int t, vector <int> &par, vector <int> &time) {
        par[node] = p;
        time[node] = t;

        for(auto x: adj[node]) {
            if(x == p)
                continue;
            solve(adj, x, node, t + 1, par, time);
        } 
    }

    int dfs(vector <vector <int> > &adj, int node, vector <int> &am, int p) {
        int maxi = INT_MIN;

        for(auto x: adj[node]) {
            if(x == p)
                continue;
            
            maxi = max(maxi, dfs(adj, x, am, node));
        }

        return (maxi == INT_MIN) ? am[node] : maxi + am[node];
    }

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1;
        vector <vector <int> > adj(n);

        for(int i = 0; i < n - 1; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector <int> par(n, -1), time(n);
        solve(adj, 0, -1, 0, par, time);
        int dist = 0;

        while(bob) {

            if(time[bob] > dist)
                amount[bob] = 0;
            
            else if(time[bob] == dist)
                amount[bob] /= 2;
            
            bob = par[bob];
            dist++;
        }

        return dfs(adj, 0, amount, -1);
    }
};
