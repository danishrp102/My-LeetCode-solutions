// Problem link: https://leetcode.com/problems/kth-missing-positive-number/description/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size(), ind = 0;
        int cnt = 0, i = 1, prev = i;

        while(cnt < k) {
            prev = i;
            if(ind != n) {
                if(arr[ind] == i)
                    i++, ind++;
                else
                    i++, cnt++;
            }

            else
                i++, cnt++;
        }

        return prev;
    }
};
