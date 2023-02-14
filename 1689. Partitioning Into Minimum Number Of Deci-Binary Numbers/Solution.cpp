// Problem link: https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/description/

class Solution {
public:
    int minPartitions(string n) {
        int maxi = -1;
        for(int i = 0; i < n.size(); i++) {
            maxi = max(maxi, n[i] - '0');
        }

        return maxi;
    }
};
