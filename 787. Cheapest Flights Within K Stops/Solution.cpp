// Problem Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

// The solution for this problem involves the use of min-heap (priority queue in C++) for implementing a slight modification of the Dijkstra's algorithm for the shortest paths
// The priority queue will first sort on the basis of minimum hops (to traverse the shortest routes first and then exploring the longer routes)

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector <vector <pair <int, int> > > adj(n);
        for(auto x: flights)
            adj[x[0]].push_back(make_pair(x[1], x[2]));

        priority_queue <pair <int, pair <int, int> >, vector <pair <int, pair <int, int> > >, greater <pair <int, pair <int, int> > > > pq;
        // min heap

        vector <int> dist(n, INT_MAX);
        dist[src] = 0; // starting point

        pq.push(make_pair(-1, make_pair(0, src)));
        // first no of hops, then distance, then the node
        // so that we traverse throught the shorter routes first

        while(!pq.empty()) {
            pair <int, int> p = pq.top().second;
            int hops = pq.top().first;
            int node = p.second;
            int wt = p.first;
            pq.pop();

            for(auto x: adj[node]) {
                if((hops + 1) <= k && dist[x.first] > wt + x.second) {
                    dist[x.first] = wt + x.second;
                    pq.push(make_pair(hops + 1, make_pair(dist[x.first], x.first)));
                }
            }
        } 

        if(dist[dst] != INT_MAX)
            return dist[dst];
        return -1;
    }
};
