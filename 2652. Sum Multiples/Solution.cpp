// Problem link: https://leetcode.com/problems/sum-multiples/

class Solution {
public:
    int sumOfMultiples(int n) {
        vector <bool> sieve(n + 1, false);
        
        for(int i = 3; i <= n; i += 3)
            sieve[i] = true;
    
        for(int i = 5; i <= n; i += 5)
            sieve[i] = true;
        
        for(int i = 7; i <= n; i += 7)
            sieve[i] = true;
        
        int sum = 0;
        for(int i = 3; i <= n; i++)
            if(sieve[i])
                sum += i;
        
        return sum;
    }
};
