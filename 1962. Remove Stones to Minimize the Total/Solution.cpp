// Problem link: https://leetcode.com/problems/remove-stones-to-minimize-the-total/description/

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue <int> pq;
        int n = piles.size();

        for(int i = 0; i < n; i++)
            pq.push(piles[i]);
        
        for(int i = 0; i < k; i++) {
            int val = pq.top();
    
            if(val == 0)
                break;
            pq.pop();
            pq.push(val - val / 2);
        }

        int sum = 0;
        while(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};
