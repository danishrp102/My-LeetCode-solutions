// Problem link: https://leetcode.com/problems/boats-to-save-people/description/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());

        int i = 0, j = n - 1, ans = 0;
        while(i < j) {
            int sum = people[i] + people[j];

            if(sum <= limit)
                i++;

            j--;
            ans++;
        }

        if(i == j)
            ans++;
        
        return ans;
    }
};
