// Problem link: https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/

class Solution {
public:
    int minMaxDifference(int num) {
        vector <int> v1, v2;
        int n = num;
        while(n) {
            v1.push_back(n % 10);
            v2.push_back(n % 10);
            n /= 10;
        }
        
        int large = v1.back();
        int small = v1.back();
        
        if(large == 9) {
            for(int i = v1.size() - 1; i >= 0; i--) {
                if(v1[i] != 9) {
                    large = v1[i];
                    break;
                }
            }
        }
        
        for(int i = 0; i < v1.size(); i++) {
            if(v1[i] == large) {
                v1[i] = 9;
            }
            
            if(v2[i] == small)
                v2[i] = 0;
        }
        
        reverse(v1.begin(), v1.end());
        reverse(v2.begin(), v2.end());
        
        int l = 0, r = 0;
        
        for(int i = 0; i < v1.size(); i++) {
            l *= 10;
            l += v1[i];
            r *= 10;
            r += v2[i];
        }
    
        
        return l - r;
    }
};
