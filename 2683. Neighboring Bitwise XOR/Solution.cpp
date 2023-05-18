// Problem link: https://leetcode.com/problems/neighboring-bitwise-xor/description/

// Solution 1(shortest) - learned:

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int cnt = count(derived.begin(), derived.end(), 1);

        return (cnt & 1) ^ true;
    }
};

// Solution 2(short) - learned:

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size(), XOR = 0;

        for(int i = 0; i < n; i++)
            XOR ^= derived[i];
        
        return XOR ^ true;
    }
};

// Solution 3(long) - own:

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size(), cnt = 0;
        bool flag = true;
        
        for(int i = 0; i < n; i++) {
            if(derived[i] == 1)
                cnt++;
            
            else if(derived[i] == 0) {
                if(cnt & 1)
                    flag ^= true; // flag = !flag;
                
                cnt = 0;
            }
        }
        
        if(cnt & 1)
            flag ^= true; // flag = !flag;
        
        return flag;
    }
};
