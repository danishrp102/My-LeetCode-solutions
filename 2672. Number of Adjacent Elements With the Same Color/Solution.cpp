// Problem link: https://leetcode.com/problems/number-of-adjacent-elements-with-the-same-color/description/

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        int m = queries.size(), val = 0;
        vector <int> nums(n + 2, 0), ans(m, 0);
        
        for(int i = 0; i < m; i++) {
            
            int ind = queries[i][0] + 1;
            if(nums[ind] == nums[ind + 1] && nums[ind] != 0)
                val--;
            if(nums[ind] == nums[ind - 1] && nums[ind] != 0)
                val--;
            
            nums[ind] = queries[i][1];
            
            if(nums[ind] == nums[ind + 1] && nums[ind] != 0)
                val++;
            if(nums[ind] == nums[ind - 1] && nums[ind] != 0)
                val++;
            
            ans[i] = val;
        }
        
        return ans;
    }
};
