// Problem Link: https://leetcode.com/problems/guess-number-higher-or-lower/description/

class Solution {
public:
    int guessNumber(int n) {
        int low = 0, high = n, mid;

        while(low <= high) {
            mid = low + (high - low) / 2;
            int val = guess(mid);
            if(val == 0)
                return mid;
            else if(val == -1)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return 0;
    }
};
