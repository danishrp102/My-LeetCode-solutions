// Problem link: https://leetcode.com/problems/detonate-the-maximum-bombs/description/

class Solution {
private:
    int check(int x1, int y1, int r1, int x2, int y2, int r2) {
        double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        if(dist <= r1 && dist <= r2)
            return 3;
        if(dist <= r1)
            return 1;
        if(dist <= r2)
            return 2;
        
        return 0;
    }

    int solve(vector <vector <int> > &adj, int src, int &n) {
        vector <bool> vis(n, false);
        queue <int> q;
        q.push(src);
        vis[src] = true;
        int cnt = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;

            for(auto x: adj[node]) {
                if(!vis[x]) {
                    q.push(x);
                    vis[x] = true;
                }
            }
        }

        return cnt;
    }

public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector <vector <int> > adj(n);

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int ans = check(bombs[i][0], bombs[i][1], bombs[i][2], bombs[j][0], bombs[j][1], bombs[j][2]);
                if(ans == 3)
                    adj[i].push_back(j), adj[j].push_back(i);
                else if(ans == 2)
                    adj[j].push_back(i);
                else if(ans == 1)
                    adj[i].push_back(j);
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++)
            ans = max(ans, solve(adj, i, n));
        
        return ans;
    }
};
