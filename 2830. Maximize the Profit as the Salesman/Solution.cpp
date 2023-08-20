// Problem link: https://leetcode.com/problems/maximize-the-profit-as-the-salesman/

class Solution {
private:

    static bool cmp(vector <int> &a, vector <int> &b) {
        return (a[1] < b[1]);
    }

    int find_ind(vector <vector <int> > &v, int i) {

        int l = 0, r = i - 1, mid;
        while(l <= r) {
            mid = l + (r - l) / 2;
            if(v[mid][1] < v[i][0])
                l = mid + 1;
            else
                r = mid - 1;
        }

        // when r is -1 => l = 0 and r = 0 => no index found
        return r;
    }

    int solve(int m, vector <vector <int> > &v) {
        vector <int> dp(m);
        dp[0] = v[0][2];

        for(int i = 1; i < m; i++) {
            int include = v[i][2];

            int ind = find_ind(v, i);
            if(ind != -1)
                include += dp[ind];
            
            dp[i] = max(dp[i - 1], include);
        }

        return dp[m - 1];
    }

public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end(), cmp);
        int m = offers.size();

        return solve(m, offers);
    }
};
