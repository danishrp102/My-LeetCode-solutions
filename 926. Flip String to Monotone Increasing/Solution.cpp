class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector <int> pref(n + 1);

        if(n == 1)
            return 0;

        for(int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (s[i] - '0');
        }

        int mini = INT_MAX;
        for(int i = 0; i <= n; i++) {
            int tmp = pref[i] + (n - i) - (pref[n] - pref[i]);
            mini = min(mini, tmp);
        }

        return mini;
    }
};
