class Solution {
public:

    void solve(int node, vector <vector <int> > &adj, vector <bool> &vis, int &ans) {
        vis[node] = true;
        ans++;
        for(auto x: adj[node]) {
            if(!vis[x])
                solve(x, adj, vis, ans);
        }
    } 

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size(), ans = 0;
        vector <bool> vis(n, false);
        solve(0, rooms, vis, ans);
        return (ans == n);
    }
};
