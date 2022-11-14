// Problem link: https://leetcode.com/problems/possible-bipartition/description/
// Explanation: Feed the 'dislikes' array into an adjacency list for an undirected graph (if A dislikes B => B dislikes A)
// Check if the resultant graph is bipartite or not. What it means is check if adjacent nodes are of the same colour or not
// If adjacent nodes are found to be of the same colour, then return false, else return true

class Solution {
public:

    bool solve(int node, vector <vector <int> > &adj, vector <int> &colour) {

        for(auto x: adj[node]) {
            if(colour[x] == -1) {
                colour[x] = 1 - colour[node];
                if(!solve(x, adj, colour))
                    return false;
            }

            else if(colour[x] == colour[node])
                return false;
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector <int> colour(n, -1);
        vector <vector <int> > adj(n);
        for(auto x: dislikes) {
            adj[x[0] - 1].push_back(x[1] - 1);
            adj[x[1] - 1].push_back(x[0] - 1);
        }

        for(int i = 0; i < n; i++) {
            if(colour[i] == -1) {
                colour[i] = 0;
                if(!solve(i, adj, colour))
                    return false;
            }
        }
        return true;
    }
};
