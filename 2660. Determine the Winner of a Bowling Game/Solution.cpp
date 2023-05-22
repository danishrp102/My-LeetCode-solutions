// Problem link: https://leetcode.com/problems/determine-the-winner-of-a-bowling-game/description/

class Solution {
private:
    bool check(vector <int> &v, int i) {
        return ((i - 1 >= 0 && v[i - 1] == 10) || (i - 2 >= 0 && v[i - 2] == 10));
    }
    
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int ans1 = 0, ans2 = 0, n = player1.size();
        
        for(int i = 0; i < n; i++) {
            ans1 += check(player1, i) ? 2 * player1[i] : player1[i];
            ans2 += check(player2, i) ? 2 * player2[i] : player2[i];
        }
        
        if(ans1 > ans2)
            return 1;
        else if(ans1 == ans2)
            return 0;
        else
            return 2;
    }
};
