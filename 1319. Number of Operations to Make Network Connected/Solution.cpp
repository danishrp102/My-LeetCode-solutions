// Problem link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

class Solution {
public:

    void solve(int node, vector <bool> &vis, vector <vector <int> > &adj) {
        vis[node] = true;

        for(auto x: adj[node]) {
            if(!vis[x])
                solve(x, vis, adj);
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int siz = connections.size();
        if(siz < n - 1)
            return -1;
        
        vector <vector <int> > adj(n);
        vector <bool> vis(n, false);
        for(int i = 0; i < siz; i++) {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                ans++;
                solve(i, vis, adj);
            }
        }

        return ans - 1;
    }
};
