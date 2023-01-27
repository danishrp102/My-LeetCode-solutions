// Problem link: https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/description/

class Solution {
public:

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector <vector <int> > ans(n), adj(n);
        vector <int> inDegree(n, 0);
        vector <set <int> > s(n);

        for(auto x: edges) {
            adj[x[0]].push_back(x[1]);
            inDegree[x[1]]++;
        }

        queue <int> q;

        for(int i = 0; i < n; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto x: adj[node]) {
                for(auto y: s[node]) {
                    s[x].insert(y);
                }

                s[x].insert(node);
                inDegree[x]--;

                if(inDegree[x] == 0)
                    q.push(x);
            }
        }

        for(int i = 0; i < n; i++) {
            for(auto x: s[i])
                ans[i].push_back(x);
        } 

        return ans;
        
    }
};
