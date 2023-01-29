// Problem link: https://leetcode.com/problems/count-collisions-of-monkeys-on-a-polygon/description/

class Solution {
public:

    long long int mul(long long int x, long long int y, const long long int &mod) {
        long long int res = x * y;
        return (res >= mod ? res % mod : res);
    }

    int monkeyMove(int n) {
        const long long int mod = 1e9 + 7;
        long long int ans = 1, x = 2;

        while(n) {
            x %= mod;
            if(n & 1)
                ans = mul(ans, x, mod);
            n >>= 1;
            x = mul(x, x, mod);
        }

        ans -= 2;
        return (ans <= 0) ? ans + mod : ans;
    }
};
