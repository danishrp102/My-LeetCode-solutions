// Problem link: https://leetcode.com/problems/partition-array-into-disjoint-intervals/description/

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size(), maxi = INT_MIN;

        vector <int> mini(n, nums[n - 1]);
        
        for(int i = n - 2; i >= 0; i--)
            mini[i] = min(mini[i + 1], nums[i]);

        for(int i = 0; i < n - 1; i++) {
            maxi = max(maxi, nums[i]);

            if(maxi <= mini[i + 1])
                return i + 1;                
        }

        return -1;
    }
};
