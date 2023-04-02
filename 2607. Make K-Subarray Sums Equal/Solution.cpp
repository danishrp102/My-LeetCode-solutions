// Problem link: https://leetcode.com/problems/make-k-subarray-sums-equal/description/

class Solution {
public:

    long long solve(vector <int> &v, int n) {
        sort(v.begin(), v.end());

        int mid = n / 2;
        long long sum = 0;

        for(int i = 0; i < n; i++)
            sum += abs(v[i] - v[mid]);

        if(n % 2 == 0) {
            long long s = 0;

            for(int i = 0; i < n; i++)
                s += abs(v[i] - v[mid - 1]);

            sum = min(sum, s);
        }

        return sum;
    }

    long long makeSubKSumEqual(vector<int>& arr, int k) {
        
        long long ans = 0;
        int n = arr.size(), GCD = gcd(n, k);

        for(int i = 0; i < GCD; i++) {
            vector <int> v;
            
            for(int j = i; j < n; j += GCD)
                v.push_back(arr[j]);
            
            ans += solve(v, v.size());
        }

        return ans;
    }
};
