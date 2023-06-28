// Problem link: https://leetcode.com/problems/path-with-maximum-probability/description/

class Solution {
private:
    void solve(vector <vector <pair <int, double> > > &adj, int src, int dest, vector <double> &dist) {
        priority_queue <pair <double, int> > pq;
        pq.push(make_pair(0.0, src));

        while(!pq.empty()) {
            double wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto [x, y]: adj[node]) {
                if(dist[x] < wt + y) {
                    dist[x] = wt + y;
                    pq.push(make_pair(dist[x], x));
                }
            }
        }
    }

public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector <vector <pair <int, double> > > adj(n);
        int m = edges.size();

        for(int i = 0; i < m; i++) {
            double prob = (succProb[i] > 0) ? log2(succProb[i]) : 1e5;
            adj[edges[i][0]].push_back(make_pair(edges[i][1], prob));
            adj[edges[i][1]].push_back(make_pair(edges[i][0], prob));
        }

        vector <double> dist(n, INT_MIN);
        dist[start] = 0.0;

        solve(adj, start, end, dist);
        return pow(2, dist[end]);
    }
};
