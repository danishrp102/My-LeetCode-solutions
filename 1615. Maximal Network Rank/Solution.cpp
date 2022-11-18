// Problem link: https://leetcode.com/problems/maximal-network-rank/description/

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector <int> inDegree(n, 0);
        vector <vector <int> > adj(n, vector <int>(n, 0));
        
        for(auto x: roads) {
            inDegree[x[0]]++;
            inDegree[x[1]]++;
            adj[x[0]][x[1]] = 1;
            adj[x[1]][x[0]] = 1;
        }

        int maxi = -1;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int cnt = inDegree[i] + inDegree[j];
                if(adj[i][j])   
                    cnt--;
                maxi = max(maxi, cnt);
            }
        }

        return maxi;
    }
};
