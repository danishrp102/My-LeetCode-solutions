// Problem link: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map <int, int> mp;
        int n = A.size();
        vector <int> ans(n, 0), v(n + 1, 0);
        
        v[A[0]]++;
        v[B[0]]++;
        
        if(v[A[0]] == 2)
            ans[0] = 1;
        
        for(int i = 1; i < n; i++) {
            v[A[i]]++;
            v[B[i]]++;
            
            ans[i] = ans[i - 1];
            
            if(v[A[i]] == 2)
                ans[i]++;
            
            if(v[B[i]] == 2 && A[i] != B[i])
                ans[i]++;
        }
        
        return ans;
    }
};
