// Problem link: https://leetcode.com/problems/minimum-cost-of-a-path-with-special-roads/description/

class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        int n = specialRoads.size();
        priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq;
        vector <int> dist(n, 1e9);

        for(int i = 0; i < n; i++) {
            dist[i] = abs(specialRoads[i][0] - start[0]) + abs(specialRoads[i][1] - start[1]) + specialRoads[i][4];
            pq.push(make_pair(dist[i], i));
        }

        int ans = abs(target[0] - start[0]) + abs(target[1] - start[1]);

        while(!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();

            if(wt == dist[node]) {
                ans = min(ans, wt + abs(target[0] - specialRoads[node][2]) + abs(target[1] - specialRoads[node][3]));

                for(int j = 0; j < n; j++) {
                    int w = abs(specialRoads[j][0] - specialRoads[node][2]) + abs(specialRoads[j][1] - specialRoads[node][3]) + specialRoads[j][4];
                    
                    if(w + wt < dist[j]) {
                        dist[j] = w + wt;
                        pq.push(make_pair(dist[j], j));
                    }
                }
            }
        }

        return ans;
    }
};
