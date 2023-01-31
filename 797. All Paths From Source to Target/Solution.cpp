// Problem link: https://leetcode.com/problems/all-paths-from-source-to-target/description/

class Solution {
public:

    void solve(int node, vector <int> v, vector <vector <int> > &adj, vector <bool> &vis, vector <vector <int> > &ans) {
        
        if(node == adj.size() - 1) {
            ans.push_back(v);
            return;
        }

        vis[node] = true;

        for(auto x: adj[node]) {
            if(!vis[x]) {
                v.push_back(x);
                solve(x, v, adj, vis, ans);
                v.pop_back();
            }
        }

        vis[node] = false;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();

        vector <vector <int> > ans;
        vector <bool> vis(n, false);

        solve(0, {0}, graph, vis, ans);

        return ans;
    }
};
