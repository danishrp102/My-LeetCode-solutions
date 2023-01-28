/*
Intuition:

The primary observation to be made before solving the problem is that a particular node can be a part of at most one cycle. This can be ascertained from the fact that each node can have outmost one outgoing edge, it it were multiple edges then a node could be a part of multiple cycles



Approach:

We can initialize a 'time' array to keep track of the time instant when we visit a node. This can be useful since a cycle is detected iff a node is visited twice while following the cycle of nodes. Hence the length of the cycle can be determined by the difference in the times when the node was visited.

If we encouter a dead end OR if a node is already a part of a cycle (determined if time[node] != -1), we cannot continue further. Hence we backtrack from the current path while marking the nodes not a part of a cylce as unvisited i.e, time[node] = -1.

The variable 'ans' (initialized to a negative number) stores the maximum length of the cycle obtained. Also, if a node is visited twice in a cycle, after we determine the cycle size, we update the time value of the node.

Finally we determine if the variable 'ans' is negative or not. If it is, then no cycle exists in the graph and therefore we return -1, else we return 'ans', the length of the cycle
*/


class Solution {
public:

    bool solve(int node, vector <int> &edges, int &ans, vector <int> &time, int t) {

        int next = edges[node];

        if(time[node] != -1) {
            ans = max(ans, t - time[node]);
            time[node] = t;
            return true;
        }
        
        time[node] = t;

        if(next != -1) {
            bool stat = solve(next, edges, ans, time, t + 1);    
            if(!stat) //cycle can be formed
                time[node] = -1;
            else //cycle could not be formed
                return true;
        }

        else // dead end
            time[node] = -1;

        return false;
    }

    int longestCycle(vector<int>& edges) {

        int n = edges.size(), ans = INT_MIN;
        vector <int> time(n, -1);

        for(int i = 0; i < n; i++) {
            if(time[i] == -1)
                solve(i, edges, ans, time, 0);
        }

        return (ans == INT_MIN) ? -1 : ans;
    }
};
