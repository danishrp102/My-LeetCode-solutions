// Problem URL: https://leetcode.com/problems/find-if-path-exists-in-graph/description/


// Use union find here
// Create a hierarchy of a set of nodes where each node belonging to set are characterized by a unique number: in this case, we can call that number the parent of each node in a set
// Finally, if the parent of the source node and the destination node are the same, then it is evident that the two nodes belong to the same set and thus there is a well defined path from the source node to the destination


class Solution {
public:

    void unionn(int u, int v, vector <int> &parent, vector <int> &rank) {
        u = findPar(u, parent);
        v = findPar(v, parent);

        if(rank[u] < rank[v])
            parent[u] = v;
        else if(rank[u] > rank[v])
            parent[v] = u;
        else
            parent[v] = u, rank[u]++;
    }

    int findPar(int u, vector <int> &parent) {
        if(u == parent[u])
            return u;
        
        return parent[u] = findPar(parent[u], parent);
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector <int> rank(n, 0), parent(n);

        for(int i = 0; i < n; i++)
            parent[i] = i;
        
        for(auto x: edges)
            unionn(x[0], x[1], parent, rank);

        int p1 = findPar(source, parent);
        int p2 = findPar(destination, parent);
        
        return (p1 == p2);
    }
};
