// Problem link: https://leetcode.com/problems/count-the-number-of-complete-components/description/

class Solution {
private:
    void solve(int src, vector <vector <int> > &adj, int &n, vector <bool> &vis, int &ans) {
        queue <int> q;
        q.push(src);
        vis[src] = true;
        
        int sum = 0, cnt = 0;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            sum += adj[node].size();
            
            for(auto x: adj[node]) {
                if(!vis[x]) {
                    q.push(x);
                    vis[x] = true;
                }
            }
        }
        
        if((sum / cnt) == (cnt - 1))
            ans++;
    }
    
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector <vector <int> > adj(n);
        
        for(auto x: edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        vector <int> inDegree(n, 0);
        vector <bool> vis(n, false);
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                solve(i, adj, n, vis, ans);
            }
        }
        
        return ans;
    }
};
