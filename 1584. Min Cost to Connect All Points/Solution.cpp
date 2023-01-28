// Problem link: https://leetcode.com/problems/min-cost-to-connect-all-points/description/

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map <int, pair <int, int> > mp;

        for(int i = 0; i < n; i++)
            mp[i] = make_pair(points[i][0], points[i][1]);
        
        vector <vector <pair <int, int> > > adj(n);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j)
                    continue;
                
                int dist = abs(mp[j].first - mp[i].first) + abs(mp[j].second - mp[i].second);
                adj[i].push_back(make_pair(j, dist));
            }
        }

        vector <int> key(n, INT_MAX);
        vector <bool> mst(n, false);
        key[0] = 0;

        priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq;
        pq.push(make_pair(0, 0));

        while(!pq.empty()) {
            int u = pq.top().second;
            mst[u] = true;
            pq.pop();

            for(auto x: adj[u]) {
                int v = x.first, wt = x.second;
                if(!mst[v] && wt < key[v]) {
                    key[v] = wt;
                    pq.push(make_pair(key[v], v));
                }
            }
        }

        int ans = accumulate(key.begin(), key.end(), 0);
        return ans;
    }
};
