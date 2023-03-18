// Problem link: https://leetcode.com/problems/minimum-time-to-repair-cars/description/

class Solution {
public:

    bool solve(long long time, vector <int> &r, long long cars, int &n) {
        long long cnt = 0;
        for(int i = 0; i < n; i++)
            cnt += (long long)sqrtl(time / r[i]);
        
        return (cnt >= cars);
    }

    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        int maxi = *max_element(ranks.begin(), ranks.end());

        long long l = 0, r = maxi * 1ll * cars * cars, mid, ans = -1ll;

        while(l <= r) {
            mid = l + (r - l) / 2;
            if(solve(mid, ranks, cars, n))
                ans = mid, r = mid - 1;
            else
                l = mid + 1;
        }

        return ans;
    }
};
