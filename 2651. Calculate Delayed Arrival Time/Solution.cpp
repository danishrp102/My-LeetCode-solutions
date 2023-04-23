// Problem link: https://leetcode.com/problems/calculate-delayed-arrival-time/description/

class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        int ans = arrivalTime + delayedTime;
        ans %= 24;
        return ans;
    }
};
