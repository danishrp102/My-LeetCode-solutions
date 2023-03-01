// Problem link: https://leetcode.com/problems/sort-an-array/description/

class Solution {
public:

    void merge(vector <int> &nums, int left, int mid, int right) {
        
        vector <int> a(mid - left + 1), b(right - mid);
        for(int i = 0; i < mid - left + 1; i++)
            a[i] = nums[left + i];
        for(int j = 0; j < right - mid; j++)
            b[j] = nums[mid + 1 + j];
    
        auto x1 = 0, x2 = 0, x3 = left;

        while(x1 < mid - left + 1 && x2 < right - mid) {
            if (a[x1] <= b[x2])
                nums[x3++] = a[x1++];
            else 
                nums[x3++] = b[x2++];
        }

        while(x1 < mid - left + 1)
            nums[x3++] = a[x1++];

        while (x2 < right - mid)
            nums[x3++] = b[x2++];
    }

    void mergeSort(vector <int> &nums, int const left, int const right) {
        if(left >= right)
            return;
        
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n - 1);
        return nums;
    }
};
