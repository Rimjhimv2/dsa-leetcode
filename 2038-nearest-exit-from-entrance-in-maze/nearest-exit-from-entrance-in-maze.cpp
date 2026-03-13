class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        int m = maze.size();
        int n = maze[0].size();

        // queue banao
        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});

        // entrance ko visited mark karo
        maze[entrance[0]][entrance[1]] = '+';

        int steps = 0;

        vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};

        while(!q.empty()) {

            int size = q.size();
            steps++;

            while(size--) {

                auto curr = q.front();
                q.pop();

                int r = curr.first;
                int c = curr.second;

                for(int i = 0; i < 4; i++) {

                    int newr = r + dir[i][0];
                    int newc = c + dir[i][1];

                    if(newr >= 0 && newc >= 0 && newr < m && newc < n
                       && maze[newr][newc] == '.') {

                        if(newr == 0 || newc == 0 || newr == m-1 || newc == n-1)
                            return steps;

                        maze[newr][newc] = '+';

                        q.push({newr, newc});
                    }
                }
            }
        }

        return -1;
    }
};