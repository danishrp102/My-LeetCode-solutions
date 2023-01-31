// Problem link: https://leetcode.com/problems/best-team-with-no-conflicts/description/
//  Variation of the Longest Increasing Subsequence Problem

class Solution {
public:

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();
        vector <pair <int, int> > v(n);

        for(int i = 0; i < n; i++) {
            v[i].first = ages[i];
            v[i].second = scores[i];
        } 

        sort(v.begin(), v.end());
        vector <int> dp(n);

        for(int i = 0; i < n; i++)
            dp[i] = v[i].second;

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(v[i].second >= v[j].second)
                    dp[i] = max(dp[i], dp[j] + v[i].second);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
