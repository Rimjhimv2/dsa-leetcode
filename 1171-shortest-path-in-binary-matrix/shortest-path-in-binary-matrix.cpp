class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        queue<pair<int,int>>q;
         if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
    return -1;
        q.push({0,0});

        //ab  maine queue mai 0 push kar diya hai toh ab 0 wali position ko visited mark karna padhega
        grid[0][0] = 1;

        int step = 1;
       

        int dr[] = {-1,1,0,0,-1,-1,1,1 };
        int dc[] = {0,0,-1,1,-1,1,-1,1};

        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ; i< size ; i++){
                auto[r,c] = q.front();
                q.pop();

                   if (r == n - 1 && c == n - 1)
                    return step;

                for(int k = 0; k< 8 ; k++){
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if(nr >=0 && nr < n && nc >=0 && nc < n && grid[nr][nc ]== 0){
grid[nr][nc]= 1;
q.push({nr,nc});

                    }
                }
            }
            step++;
        }


       return -1;  
    }
   
};