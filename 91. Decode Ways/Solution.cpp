// Problem link: https://leetcode.com/problems/decode-ways/description/

/*
Intuition:

We can get a better look at the bigger problem once we identify the subproblems within the problem i.e, the given string of digits can be broken down into smaller subproblems which could be easily solved using some manipulations around the given conditions and handling the base cases.

  
  
Approach:

Consider the base cases 1) and 2):

if n (= size of string) is 0, meaning that the string of digits is empty. In such case, there is only one way to decode the string.

if n(= size of string) is 1, then the digit cannot be '0' because there is no possible way to decode '0' into a character as per the described set of rules. In other cases when the digit is not '0' we return 1, as there is only one way to decode the string

Now we have a choice of decoding the string based on the number of characters chosen:

If a single character is chosen, then it should not be '0' for reasons stated in base case 2). In other cases, we resuce the size of the string by one and call the recursive function.

If two characters are chosen for decoding, the the characters must form a string that represents a. number less than "27" for it to be valid. If it is valid we call the recursive function.

The results obtained from steps 1) and 2) above for a string of size 'n' are stored in a vector of integers at position n.

The final answer, which is stored in the vector at position 'n' is returned as the answer to the problem.
*/


class Solution {
public:

    int solve(string &str, int n, vector <int> &dp) {
        if(n == 0)
            return 1;
        
        if(n == 1) {
            if(str[0] == '0')
                return 0;
            return 1;
        }

        if(dp[n] != -1)
            return dp[n];
        
        int ans = 0;

        if(str[n - 1] != '0')
            ans += solve(str, n - 1, dp);
        
        if(str[n - 2] == '1' || (str[n - 2] == '2' && str[n - 1] <= '6'))
            ans += solve(str, n - 2, dp);

        return dp[n] = ans;
    }

    int numDecodings(string s) {
        int n = s.size();
        vector <int> dp(n + 1, -1);
        return solve(s, n, dp);
    }
};
