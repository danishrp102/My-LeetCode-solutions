// Problem link: https://leetcode.com/problems/mice-and-cheese/description/

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();

        for(int i = 0; i < n; i++)
            reward1[i] -= reward2[i];

        sort(reward1.begin(), reward1.end(), greater <int>());
        int ans = accumulate(reward2.begin(), reward2.end(), 0);

        ans = accumulate(reward1.begin(), reward1.begin() + k, ans);
        return ans;
    }
};
