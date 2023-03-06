// Problem link: https://leetcode.com/problems/kth-missing-positive-number/description/

// O(n) soln:

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


// Binary Search O(log(n)) soln:

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size(), l = 0, r = n, m;

        while(l < r) {
            m = l + (r - l) / 2;
            int missing = arr[m] - (m + 1);

            if(missing < k)
                l = m + 1;
            else
                r = m;
        }

        return l + k;
        // int final_missing = arr[l] - (l + 1);
        // int ans = arr[l] + (k - final_missing); // beacuse (k - final_missing) are the extra no.s needed
        // return ans; // -> gives runtime error
    }
};
