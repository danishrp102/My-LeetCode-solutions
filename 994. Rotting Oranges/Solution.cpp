// Problem link: https://leetcode.com/problems/rotting-oranges/description/

// Explanation:

// Here we perform a level-by-level search (BFS essentially) to compute the minimum number of steps required for all the oranges to rot
// We initially push the cell value of the rotten oranges in a queue and count the number of un-rotten oranges (representes as 'cnt' in the code)
// If there are no pre-rotten oranges (i. e, if the queue is empty) and if there are no oranges left to rot(cnt == 0 is true), then the answer to the problem is 0 (since the matrix now is filled only with zeroes)
// Initialize the answer 'ans' to 0(0 minutes)
// Now for every queue iteration, we first check if there are any rotten oranges left. If there aren't any left, then we print the answer 'ans'
// If cnt > 0, then we pop out all the cells in the queue first then we check in the four adjacent cells from the rotted cell whether the orange is yet to rot or not (represented in the grid by 0)
// If the orange is yet to rot => the next cell will also rot(if there is an orange present). In such case, push the cell value in the queue and decrement cnt by one (cnt represents the count of oranges left to rot)
// Finally, if the queue size is empty while cnt is non-zero => there are some unrotten cells that cannot be reached, so we return -1 in such cases.

class Solution {
public:

    bool check(vector <vector <int> > &grid, int i, int j, int m, int n) {
        return (min(i, j) >= 0 && i < m & j < n && grid[i][j] == 1);
    }

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue <pair <int, int> > q;
        int ans = 0, cnt = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2)
                    q.push(make_pair(i, j));
                else if(grid[i][j] == 1)
                    cnt++;
            }
        }

        if(q.empty() && cnt == 0)
            return 0;

        while(!q.empty()) {
            int siz = q.size();

            if(cnt == 0)
                return ans;

            while(siz--) {
                auto [x, y] = q.front();
                q.pop();

                for(int k = 0; k < 4; k++) {
                    int nx = x + dx[k], ny = y + dy[k];

                    if(check(grid, nx, ny, m, n)) {
                        grid[nx][ny] = 2;
                        q.push(make_pair(nx, ny));
                        cnt--;
                    }
                }
            }

            ans++;
        }

        return -1;
    }
};
