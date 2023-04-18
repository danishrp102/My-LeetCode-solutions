// Problem link: https://leetcode.com/problems/minimize-the-total-price-of-the-trips/description/

// Code 1:

class Solution {
private:
    bool solve(vector <vector <int> > &adj, vector <int> &v, int node, int dest, int par) {
        
        if(node == dest) {
            v[node]++;
            return true;
        }

        bool flag = false;

        for(auto x: adj[node]) {
            if(x == par)
                continue;
            
            flag |= solve(adj, v, x, dest, node);
        }

        if(flag)
            v[node]++;
        
        return flag;
    }

    int minPrice(int node, vector <vector <int> > &adj, vector <int> &v, vector <int> &price, int par, vector <vector <int> > &dp, bool parHalved) {
        int pick = v[node] * price[node] / 2;
        int noPick = pick * 2;

        if(dp[node][parHalved] != -1)
            return dp[node][parHalved];

        for(auto x: adj[node]) {
            if(x != par)
                noPick += minPrice(x, adj, v, price, node, dp, false);
        }

        if(parHalved)
            return dp[node][parHalved] = noPick;

        for(auto x: adj[node]) {
            if(x != par)
                pick += minPrice(x, adj, v, price, node, dp, true);
        }

        return dp[node][parHalved] = min(pick, noPick);
    }

public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector <vector <int> > adj(n);
        
        for(int i = 0; i < n - 1; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector <int> v(n, 0);

        for(auto x: trips)
            solve(adj, v, x[0], x[1], -1);
        
        vector <vector <int> > dp(n + 1, vector <int>(2, -1));
        int ans = minPrice(0, adj, v, price, -1, dp, false);

        return ans;
    }
};

// Code 2:

class Solution {
private:
    bool solve(vector <vector <int> > &adj, vector <int> &v, int node, int dest, int par) {
        
        if(node == dest) {
            v[node]++;
            return true;
        }

        bool flag = false;

        for(auto x: adj[node]) {
            if(x == par)
                continue;
            
            flag |= solve(adj, v, x, dest, node);
        }

        if(flag)
            v[node]++;
        
        return flag;
    }

    pair <int, int> minPrice(int node, vector <vector <int> > &adj, vector <int> &v, vector <int> &price, int par) {
        int pick = v[node] * price[node] / 2;
        int noPick = pick * 2;

        for(auto x: adj[node]) {

            if(x == par)
                continue;
            
            pair <int, int> p = minPrice(x, adj, v, price, node);

            pick += p.second;
            noPick += min(p.first, p.second);
        }

        return make_pair(pick, noPick);
    }

public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector <vector <int> > adj(n);
        
        for(int i = 0; i < n - 1; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector <int> v(n, 0);

        for(auto x: trips)
            solve(adj, v, x[0], x[1], -1);
        
        pair <int, int> ans = minPrice(0, adj, v, price, -1);

        return min(ans.first, ans.second);
    }
};
