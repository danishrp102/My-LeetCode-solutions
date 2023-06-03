// Problem link: https://leetcode.com/problems/time-needed-to-inform-all-employees/description/

class Solution {
private:
    void solve(vector <vector <int> > &adj, int src, vector <int> &v, vector <int> &time) {
        queue <int> q;
        q.push(src);

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto x: adj[node]) {
                time[x] = time[node] + v[node];
                q.push(x);
            }
        }
    }

public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector <vector <int> > adj(n);
        for(int i = 0; i < n; i++) {
            if(i == headID)
                continue;
            adj[manager[i]].push_back(i);
        }

        vector <int> time(n, 0);
        solve(adj, headID, informTime, time);
        return *max_element(time.begin(), time.end());
    }
};
