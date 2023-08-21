// Problem link: https://leetcode.com/problems/number-of-beautiful-integers-in-the-range/description/

class Solution {
private:
    int dp[2][12][12][12][20][2];
    int k;

    int G(string &s, int tight = 1, int pos = 0, int odd = 0, int even  = 0, int sum = 0, bool zero = true) {
        
        if(pos == s.size())
            return (!zero && sum == 0 && odd == even);

        if(dp[tight][pos][odd][even][sum][zero] != -1)
            return dp[tight][pos][odd][even][sum][zero];
        
        int start = 0;
        int end = (tight ? s[pos] - '0' : 9);
        int ans = (zero ? G(s, 0, pos + 1, odd, even, sum, zero) : 0);

        for(int i = start; i <= end; i++) {
            int new_tight = (tight && (i == s[pos] - '0'));
            int new_odd = odd + (i % 2);
            int new_even = even + (((!zero) || i > 0) && (i % 2 == 0));

            if(zero && i != 0)
                ans += G(s, new_tight, pos + 1, new_odd, new_even, i, false);
            
            else if(!zero)
                ans += G(s, new_tight, pos + 1, new_odd, new_even, (sum * 10 + i) % k, false);
        }

        return dp[tight][pos][odd][even][sum][zero] = ans;

    }

public:
    int numberOfBeautifulIntegers(int low, int high, int k) {
        string a = to_string(low - 1);
        string b = to_string(high);
        this->k = k;

        memset(dp, -1, sizeof(dp));
        int r = G(b);

        memset(dp, -1, sizeof(dp));
        int l = G(a);

        return r - l;
    }
};
