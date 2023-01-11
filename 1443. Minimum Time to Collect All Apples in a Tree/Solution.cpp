// Problem link: https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/

class Solution {
public:

    int solve(vector <vector <int> > &adj, vector <bool> &valid, int node, int par) {
        int ans = 0; // stores the toal time to collect all apples from the root
        for(auto x: adj[node]) {
            if(x != par) {
                int time = solve(adj, valid, x, node); //stores whether the root's child has an apple or not
                if(valid[x]) // add 2 to the time (return distance)
                    valid[node] = true, ans += time + 2; // child has an apple => returning back confirmation
            }
        }

        return ans;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector <vector <int> > adj(n);
        
        for(auto x: edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        return solve(adj, hasApple, 0, 0);
    }
};
