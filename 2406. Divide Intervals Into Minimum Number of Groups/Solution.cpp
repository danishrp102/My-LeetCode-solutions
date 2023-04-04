// Problem link: https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/description/

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector <int>, greater<int> > pq;
        pq.push(INT_MAX);

        for(int i = 0; i < n; i++) {

            if(intervals[i][0] > pq.top())
                pq.pop();
            
            pq.push(intervals[i][1]);
        }

        return pq.size() - 1;
    }
};
