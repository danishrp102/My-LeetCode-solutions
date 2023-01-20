class Solution {
public:

    void solve(vector <int> v, int i, int &n, vector <int> &nums, set <vector <int> > &s) {
        if(i == n) {
            if(v.size() != 1)
                s.insert(v);
            
            return;
        }

        if(v.back() > nums[i]) {
            solve(v, i + 1, n, nums, s);
        }

        else {
            solve(v, i + 1, n, nums, s);
            v.push_back(nums[i]);
            solve(v, i + 1, n, nums, s);
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector <vector <int> > ans;
        set <vector <int> > s;

        for(int i = 0; i < n; i++) {
            solve({nums[i]}, i + 1, n, nums, s);
        }

        for(auto &x: s)
            ans.push_back(x);

        return ans;
    }
};
