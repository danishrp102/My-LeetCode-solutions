// Problem link: https://leetcode.com/problems/koko-eating-bananas/description/

class Solution {
public:

    bool solve(vector <int> &v, int &h, int time) {
        int t = 0;
        for(int &x: v) {
            if(x % time > 0)
                t++;
            t += (x / time);
            if(t > h)
                return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(), k = *max_element(piles.begin(), piles.end());
        int l = 1, r = k, m;

        while(l <= r) {
            m = l + (r - l) / 2;
            if(solve(piles, h, m))
                k = m, r = m - 1;
            else
                l = m + 1;
        }

        return k;
    }
};
