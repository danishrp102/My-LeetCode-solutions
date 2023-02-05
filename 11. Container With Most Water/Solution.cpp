// Problem link: https://leetcode.com/problems/container-with-most-water/description/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi = INT_MIN, n = height.size();
        int i = 0, j = n - 1;

        while(i != j) {
            maxi = max(maxi, (j - i) * min(height[i], height[j]));
            if(height[i] < height[j])
                i++;
            else
                j--;
        }

        return maxi;
    }
};
