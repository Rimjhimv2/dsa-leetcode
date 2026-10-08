class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        


 int n = grid.size();
 int m = grid[0].size();

 queue<pair<int,int>>q;
 int fresh=0;

 for(int i = 0 ; i< n ; i++){
    for(int j = 0 ; j< m ; j++){
        if(grid[i][j]==2){
            q.push({i,j});
        }
        else if(grid[i][j]==1){
             fresh++;
        }
    }
 }

 int time = 0;
 int dr[] = {-1,1,0,0};
 int dc []= {0,0,-1,1};

 while(!q.empty() && fresh>0){
     
     int size = q.size();
     while(size>0){
       
        auto[r,c] = q.front();
        q.pop();
        //rotten ornage aaya hai and eske charo side neighbour dekhna hai 
         
         for(int k = 0 ; k<4; k++){


           int nr = dr[k] + r;
           int nc = dc[k] + c;

           if(nr>= 0 && nr<n &&
            nc >=0 && nc<m &&
            grid[nr][nc] == 1){

                grid[nr][nc] = 2;

            fresh--;
            q.push({nr,nc});
          
            }

          
         }
         size--;
         //yaha se pta chalega up,d,l,r

         //ab chevck karo kya ye valid hai 

          
        
     }

     time++;
   


 }

return  fresh == 0 ? time : -1;
    }
};