// Problem link: https://leetcode.com/problems/flower-planting-with-no-adjacent/description/
// Explanation: This problem is similar to the M-Colouring problem where we have to check if this particular node can be coloured with a colour 'm' while checking if such a placement is valid

class Solution {
public:

    bool check(int node, int col, vector <vector <int> > &adj, vector <int> &ans) {
        for(auto x: adj[node])
            if(ans[x] == col)
                return false;
        return true;
    }

    void solve(int node, vector <bool> &vis, vector <vector <int> > &adj, vector <int> &ans) {
        vis[node] = true;

        for(auto x: adj[node]) {
            if(!vis[x]) {
                for(int i = 1; i <= 4; i++) {
                    if(check(x, i, adj, ans)) {
                        ans[x] = i;
                        solve(x, vis, adj, ans);
                    }
                }
            }
        }
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector <vector <int> > adj(n);
        for(auto x: paths) {
            adj[x[0] - 1].push_back(x[1] - 1);
            adj[x[1] - 1].push_back(x[0] - 1);
        }

        vector <bool> vis(n, false);
        vector <int> ans(n, -1);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                ans[i] = 1;
                solve(i, vis, adj, ans);
            }
        }

        return ans;
    }
};
