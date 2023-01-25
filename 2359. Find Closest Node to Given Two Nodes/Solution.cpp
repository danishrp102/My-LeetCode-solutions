// Problem link: https://leetcode.com/problems/find-closest-node-to-given-two-nodes/description/

class Solution {
public:

    void solve(int node, vector <int> &v, vector <int> &list, vector <bool> &vis, int level) {

        vis[node] = true;
        list[node] = level;

        if(v[node] != -1 && !vis[v[node]])
            solve(v[node], v, list, vis, level + 1);
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector <int> v1(n, -1), v2(n, -1);
        vector <bool> vis1(n, false), vis2(n, false);

        solve(node1, edges, v1, vis1, 0);
        solve(node2, edges, v2, vis2, 0);

        int ans = INT_MAX;
        int ele = -1;

        for(int i = 0; i < n; i++) {
            if(v1[i] == -1 || v2[i] == -1)
                continue;
            
            if(max(v1[i], v2[i]) < ans) {
                ans = max(v1[i], v2[i]);
                ele = i;
            }
        }

        return (ans == INT_MAX) ? -1 : ele;
    }
};
