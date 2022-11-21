// Problem link: https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/

// Method 1:

// Modified dijksta's algorithm for the matrix shortest path (slower):

// Code:

class Solution {
public:

    bool check(vector <vector <char> > &maze, int m, int n, int i, int j) {
        return (min(i, j) >= 0 && i < m && j < n && maze[i][j] == '.');
    } 

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        vector <vector <int> > dist(m, vector <int>(n, INT_MAX));

        priority_queue <pair <int, pair <int, int> >, vector <pair <int, pair <int, int> > >, greater <pair <int, pair <int, int> > > > pq;

        dist[entrance[0]][entrance[1]] = 0;
        pq.push(make_pair(0, make_pair(entrance[0], entrance[1])));

        while(!pq.empty()) {
            int wt = pq.top().first;
            auto [x, y] = pq.top().second;
            pq.pop();

            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];

                if(check(maze, m, n, nx, ny)) {
                    if(dist[nx][ny] > wt + 1) {
                        dist[nx][ny] = wt + 1;
                        pq.push(make_pair(dist[nx][ny], make_pair(nx, ny)));
                    }
                }
            }
        }

        dist[entrance[0]][entrance[1]] = INT_MAX; // in no circumstances the entrance point can be an exit
        int mini = INT_MAX;

        for(int i = 0; i < m; i++)
            mini = min(mini, min(dist[i][0], dist[i][n - 1]));
        
        for(int j = 0; j < n; j++)
            mini = min(mini, min(dist[0][j], dist[m - 1][j]));
        
        return (mini == INT_MAX) ? -1 : mini;
    }
};


// Method 2:

// Simple BFS solution - level by level search (faster):

// Code:

class Solution {
public:

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    bool check(vector <vector <char> > &maze, int i, int j, int m, int n, vector <vector <bool> > &vis) {
        return(min(i, j) >= 0 && i < m && j < n && !vis[i][j] && maze[i][j] == '.');
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        vector <vector <bool> > vis(m, vector <bool>(n, false));

        queue <pair <int, int> > q;
        q.push(make_pair(entrance[0], entrance[1]));
        vis[entrance[0]][entrance[1]] = true;

        int ans = 0;

        while(!q.empty()) {
            int siz = q.size();
            
            while(siz--) {
                auto [x, y] = q.front();
                q.pop();

                if((x == 0 || x == m - 1 || y == 0 || y == n - 1) && (x != entrance[0] || y != entrance[1]))
                    return ans;

                for(int k = 0; k < 4; k++) {
                    int nx = x + dx[k], ny = y + dy[k];
                    
                    if(check(maze, nx, ny, m, n, vis)) {
                        q.push(make_pair(nx, ny));
                        vis[nx][ny] = true;
                    }
                }
            }

            ans++;
        }

        return -1;
    }
};
