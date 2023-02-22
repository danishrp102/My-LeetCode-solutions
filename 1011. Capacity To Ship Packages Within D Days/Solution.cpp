// Problem link:  https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

class Solution {
public:

    bool solve(vector <int> &v, int d, int cap, int &n) {
        int i = 0, sum = 0;

        while(i < n && d) {
            sum += v[i];

            if(sum < cap)
                i++;

            else if(sum == cap) {
                d--;
                sum = 0;
                i++;
            }

            else if(sum > cap) {
                sum = v[i];
                d--;
                i++;
            }
        }

        if(sum)
            d--;

        if(d < 0 || i < n)
            return false;
        
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size(), mid;
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low <= high) {
            mid = low + (high - low) / 2;

            if(solve(weights, days, mid, n))
                high = mid - 1;

            else
                low = mid + 1;
        }

        return low;
    }
};
