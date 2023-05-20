// Problem link: https://leetcode.com/problems/evaluate-division/description/

class Solution {
private:
    double solve(unordered_map <string, unordered_map <string, double> > &mp, string src, string &dest, unordered_set <string> &vis) {
        if(mp[src].empty())
            return -1.0;
        
        if(mp[src].find(dest) != mp[src].end())
            return mp[src][dest];
        
        vis.insert(src);
        for(auto [x, y]: mp[src]) {
            if(vis.find(x) == vis.end()) {
                double val = solve(mp, x, dest, vis);
                if(val != -1.0)
                    return y * val;
            }
        }

        return -1.0;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map <string, unordered_map <string, double> > mp;
        int n = values.size(), m = queries.size();
        vector <double> ans(m, -1.0);

        for(int i = 0; i < n; i++) {
            mp[equations[i][0]][equations[i][1]] = values[i];
            mp[equations[i][1]][equations[i][0]] = 1.0 / values[i];
        }

        for(int i = 0; i < m; i++) {
            unordered_set <string> vis;
            ans[i] = solve(mp, queries[i][0], queries[i][1], vis);
        }

        return ans;
    }
};
