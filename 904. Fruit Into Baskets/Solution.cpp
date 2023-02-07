// Problem link: https://leetcode.com/problems/fruit-into-baskets/description/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxi = INT_MIN;
        int k1 = -1, k2 = -1, i = 0;
        int n = fruits.size();

        unordered_map <int, int> mp, pos;

        while(i < n) {

            if(k1 == -1)
                k1 = fruits[i], mp[k1]++, pos[k1] = i;

            else if(k2 == -1) {

                if(k1 != fruits[i])
                    k2 = fruits[i], mp[k2]++, pos[k2] = i;
                else
                    mp[k1]++, pos[k1] = i;
            }

            else {

                if(k1 == fruits[i])
                    mp[k1]++, pos[k1] = i;

                else if(k2 == fruits[i])
                    mp[k2]++, pos[k2] = i;

                else {

                    if(fruits[i - 1] == k1) {
                        mp.erase(k2);
                        mp[k1] = (i - 1) - pos[k2];
                        k2 = fruits[i];
                        mp[k2]++;
                        pos[k2] = i;
                    }

                    else if(fruits[i - 1] == k2) {
                        mp.erase(k1);
                        mp[k2] = (i - 1) - pos[k1];
                        k1 = fruits[i];
                        mp[k1]++;
                        pos[k1] = i;
                    }

                }
            }

            maxi = max(maxi, mp[k1] + mp[k2]);
            i++;
        }

        return maxi;
    }
};
