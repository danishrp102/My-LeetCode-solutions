// Problem link: https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/description/

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        
        int n = nums.size();
        vector <int> v(value, 0);
        for(int i = 0; i < n; i++) {
            v[((nums[i] % value) + value) % value]++;
        }
        
        int mini = *min_element(v.begin(), v.end());
        int pos = find(v.begin(), v.end(), mini) - v.begin();
        
        return (mini * value + pos);
    }
};
