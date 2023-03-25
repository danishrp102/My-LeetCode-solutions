// Problem link: https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/

class Solution {
public:

    void solve(vector <vector <int> > &adj, int node, vector <bool> &vis, long long &cnt) {
        vis[node] = true;
        cnt++;

        for(auto x: adj[node]) {
            if(!vis[x]) {
                solve(adj, x, vis, cnt);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans = 0, tot = 0, cnt;
        vector <vector <int> > adj(n);

        for(auto x: edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        vector <bool> vis(n, false);

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                cnt = 0;
                solve(adj, i, vis, cnt);
                tot += cnt;
                ans += cnt * (n - tot);
            }
        }

        return ans;
    }
};
