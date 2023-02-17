// Problem link: https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/description/

class Solution {
public:
    int countOrders(int n) {
        
        const int mod = 1e9 + 7;
        long long int ans = 1;

        for(int i = 1; i <= n; i++)
            ans = (ans * (i * 2 - 1) * i) % mod;

        return ans;
    }
};
