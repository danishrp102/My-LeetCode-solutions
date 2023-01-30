// Problem link: https://leetcode.com/problems/ugly-number-ii/description/

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue <long long int, vector <long long int>, greater <long long int> > pq;

        if(n == 1)
            return 1;

        pq.push(1);
        unordered_map <long long int, int> mp;

        while(n--) {

            while(mp.count(pq.top())) {
                pq.pop();
            }

            long long int x = pq.top();
            mp[x]++;

            pq.push(x * 2);
            pq.push(x * 3);
            pq.push(x * 5);
        }

        return pq.top();
    }
};
