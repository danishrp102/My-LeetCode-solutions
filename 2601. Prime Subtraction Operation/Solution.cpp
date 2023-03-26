// Problem link: https://leetcode.com/problems/prime-subtraction-operation/description/

class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        vector <bool> seive(1002, true);
        vector <int> p;
        seive[0] = seive[1] = false;

        for(int i = 2; i <= 1002; i++) {
            if(seive[i]) {
                p.push_back(i);
                for(int j = i * i; j <= 1002; j += i)
                    seive[j] = false;
            }
        }

        for(int i = 0; i < n; i++) {
            if(i == 0) {
                int pos = lower_bound(p.begin(), p.end(), nums[i]) - p.begin();
                if(pos == 0)
                    continue;
                nums[i] -= p[pos - 1];
                continue;
            }

            int pos = lower_bound(p.begin(), p.end(), nums[i] - nums[i - 1]) - p.begin();
            if(pos == 0)
                continue;
            nums[i] -= p[pos - 1];
        }

        for(int i = 1; i < n; i++)
            if(nums[i] <= nums[i - 1])
                return false;
        
        return true;
    }
};
