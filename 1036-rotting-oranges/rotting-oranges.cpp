 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> que;
        int freshCount = 0;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 2)
                    que.push({i,j});
                else if(grid[i][j] == 1)
                    freshCount++;
            }
        }

        // ✅ Fix
        if(freshCount == 0) return 0;

        vector<vector<int>> directions = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        int minutes = 0;

        while(!que.empty()){

            int n = que.size();

            while(n--){

                auto curr = que.front();
                que.pop();

                int i = curr.first;
                int j = curr.second;

                for(auto &dir : directions){

                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if(new_i >= 0 && new_j >= 0 &&
                       new_i < rows && new_j < cols &&
                       grid[new_i][new_j] == 1){

                        grid[new_i][new_j] = 2;
                        que.push({new_i,new_j});
                        freshCount--;
                    }
                }
            }

            minutes++;
        }

        return freshCount == 0 ? minutes - 1 : -1;
    }
};
//phle hi nikal lo ki current level mai kitni rotten eggs hai 
//and phle ye nikalo ki current level ko process krlo
//matlab simultaneosly sare rotten egg ko process karo 
//jse hi ek level kahtam (curerent) tab ham minute ko increase kardeng 
//and while loop ke khtm hone ke baad 