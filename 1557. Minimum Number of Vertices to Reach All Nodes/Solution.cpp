// Problem link: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector <int> inDegree(n, 0);
        vector <int> ans;
        
        for(auto x: edges)
            inDegree[x[1]]++;

        for(int i = 0; i < n; i++)
            if(inDegree[i] == 0)
                ans.push_back(i);

        return ans;
    }
};
