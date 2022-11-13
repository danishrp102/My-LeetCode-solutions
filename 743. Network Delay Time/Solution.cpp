// Problem link- https://leetcode.com/problems/network-delay-time/description/

// at first I tried to solve this problem using topological sort. The idea was if we find out that the top of the stack after the topological sort is not equal to k(the given source), then we return -1
// But this solution fails in cases where the given graph is not a DAG (eg: times = [[1,2,1],[2,1,3]])
// So I applied the Dijkstra's algorithm for directed graphs and formed the solution
// Explanation: create a min-heap (priority queue in C++) to store a pair of integers: (min distance to the node, node value)
// find out if from this state we can reach all adjoining states in minimum time, if yes, push such states in the min-heap
// Continue the process while updating the minimum distances in a dist[] array
// Finally we calculate the maximum distance of all elements in the dist[] array. By doing so, we find out that the maximum element = minimum time taken to reach all the nodes from the given source 'k'
// If the maximum value is found out to be INT_MAX (representing infinity) => we cannot reach such nodes with this large distance. In such cases, return -1
// else return the maximum distance

class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector <vector <pair <int, int> > > adj(n + 1);
        for(auto x: times)
            adj[x[0]].push_back(make_pair(x[1], x[2]));
        
        priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq;
        // for the min heap

        vector <int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        pq.push(make_pair(0, k));
        // first the distance and then the node

        while(!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto x: adj[node]) {
                if(dist[x.first] > dist[node] + x.second) {
                    dist[x.first] = dist[node] + x.second;
                    pq.push(make_pair(dist[x.first], x.first));
                }
            }
        }

        int ans = -1;
        for(int i = 1; i <= n; i++)
            ans = max(ans, dist[i]);

        if(ans == INT_MAX)
            return -1;
        return ans;
    }
};
