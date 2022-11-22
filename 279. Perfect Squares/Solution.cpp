// Problem link: https://leetcode.com/problems/perfect-squares/description/

// Explanation:

// If a number is a perfect square it can be written as a sum of itself once.
  
// So if the input number is a perfect square, we return 1(need just one number to represent the sum)

// If the number 'n' is not a perfect square then the minimum number of perfect square numbers needed so that their sum equals to 'n' can be obtained by taking the minimum of all the the answers for the numbers 'n - (i * i)' and adding 1 to it(from these cells, we add a perfect square to reach 'n') where 'n - (i * i)' is greater than 0.
  
class Solution {
public:
    int numSquares(int n) {
        vector <int> dp(n + 1, INT_MAX);
        dp[0] = dp[1] = 1;
        double d = sqrt(n);
        int val = floor(d);

        if(val * val == n)
            return 1;

        for(int i = 1; i <= val; i++)
            dp[i * i] = 1;

        for(int i = 2; i <= n; i++) {
            double d = sqrt(i);
            int val = floor(d);

            for(int j = val; j >= 1; j--)
                dp[i] = min(dp[i], 1 + dp[i - (j * j)]);
        }

        return dp[n];
    }
};
