// Problem link: https://leetcode.com/problems/last-stone-weight/description/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue <int> pq;
        for(auto &x: stones)   
            pq.push(x);
        
        while(pq.size() != 1) {
            if(pq.size() == 0)
                return 0;
            
            int t1 = pq.top();
            pq.pop();
            int t2 = pq.top();
            pq.pop();

            if(t1 != t2)
                pq.push(abs(t1 - t2));
        }

        return pq.top();
    }
};
