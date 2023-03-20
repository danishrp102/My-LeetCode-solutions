// Problem link: https://leetcode.com/problems/can-place-flowers/description/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int siz = flowerbed.size(), i = -2, j, cnt = 0;
        
        for(j = 0; j < siz; j++) {
            if(flowerbed[j] == 1) {
                cnt += max(0, (j - i - 2) / 2);
                i = j;
            }
        }

        cnt += max(0, (siz - i - 1) / 2); // (siz + 1 - i -2) / 2
        return (cnt >= n);   
    }
};
