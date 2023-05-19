// Problem link: https://leetcode.com/problems/is-graph-bipartite/description/

class Solution {
private:
    bool solve(int node, int par, vector <vector <int> > &adj, vector <bool> &vis, vector <int> &colour) {
        vis[node] = true;

        for(auto x: adj[node]) {
            if(x == par)
                continue;
            
            if(vis[x] && colour[x] == colour[node])
                return false;

            if(!vis[x]) {
                colour[x] = 1 - colour[node];
                if(!solve(x, node, adj, vis, colour))
                    return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector <int> colour(n, 0);
        vector <bool> vis(n, false);

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                if(!solve(i, -1, graph, vis, colour))
                    return false;
            }
        }

        return true;
    }
};
