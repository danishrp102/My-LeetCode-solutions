// Problem link: https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score/description/

class Solution {
public:
    int maxScore(vector<int>& nums) {
        int ans = 0, n = nums.size();
        long long sum = 0;
        vector <int> neg;
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0)
                ans++, sum += nums[i];
            else
                neg.push_back(nums[i]);
        }
    
        sort(neg.begin(), neg.end(), greater<int>());
        int siz = neg.size();
        
        for(int i = 0; i < siz; i++) {
            sum += neg[i];
            if(sum > 0)
                ans++;
            else
                break;
        }
        
        return ans;
    }
};
