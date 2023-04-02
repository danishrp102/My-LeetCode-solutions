// Problem link: https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/description/

class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int m = nums1.size(), n = nums2.size();
        
        for(int i = 0, j = 0; i < m && j < n;) {
            if(nums1[i] == nums2[j])
                return nums1[i];
            
            else if(nums1[i] > nums2[j])
                j++;
            
            else
                i++;
        }
        
        int mini1 = nums1[0], mini2 = nums2[0];
         
        if(mini1 > mini2)
            swap(mini1, mini2);

        mini1 *= 10;
        mini1 += mini2;

        return mini1;
    }
};
