// Problem link: https://leetcode.com/problems/sliding-subarray-beauty/description/

class Solution {
private:
    int solve(map <int, int> &mp, int val) {
        int cnt = 0;
        for(auto [x, y]: mp) {
            if(cnt <= val && val <= cnt + y)
                return x;
            cnt += y;
        }

        return 0;
    }

public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        map <int, int> mp;
        int i = 0, j = 0, cnt = 0;
        vector <int> ans(n - k + 1);

        while(j < n) {
            if(nums[j] < 0) {
                mp[nums[j]]++;
                cnt++;
            }

            if(j - i + 1 < k)
                j++;

            else if(j - i + 1 == k) {

                if(cnt < x)
                    ans[i] = 0;
                else
                    ans[i] = solve(mp, x);

                if(nums[i] < 0) {
                    mp[nums[i]]--;
                    if(mp[nums[i]] == 0)
                        mp.erase(nums[i]);
                    cnt--;
                }

                i++, j++;
            }
        }

        return ans;
    }
};
