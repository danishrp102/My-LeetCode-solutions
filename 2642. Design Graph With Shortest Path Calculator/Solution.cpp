// Problem link: https://leetcode.com/problems/design-graph-with-shortest-path-calculator/description/

class Graph {
private:
    vector <vector <pair <int, int> > > adj;
    int N;

    int solve(int src, int dest) {
        vector <int> dist(N, INT_MAX);

        priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq;
        dist[src] = 0;
        pq.push(make_pair(0, src));

        while(!pq.empty()) {
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            for(auto x: adj[node]) {
                if(dist[x.first] > dist[node] + x.second) {
                    dist[x.first] = dist[node] + x.second;
                    pq.push(make_pair(dist[x.first], x.first));
                }
            }
        }

        return (dist[dest] == INT_MAX) ? -1 : dist[dest];
    }
    
public:
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        N = n;
        
        for(auto x: edges)
            adj[x[0]].push_back(make_pair(x[1], x[2]));
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back(make_pair(edge[1], edge[2]));
    }
    
    int shortestPath(int node1, int node2) {
        return solve(node1, node2);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
