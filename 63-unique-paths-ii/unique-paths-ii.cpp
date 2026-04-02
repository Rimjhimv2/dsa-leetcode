class Solution {
public:
int t[101][101];
int m,n;
vector<vector<int>>grid;
int solve(int i , int j ){
if(i<0 || i>=m || j<0 || j>=n){
            return 0;
        }
        
        //phle obstackle check karo becoz destination par bhi blocked ho sjati hai esliye first check block condtion then check sucess case 
        if(grid[i][j]==1){
            return t[i][j] = 0;
        }
        ///success acse 
        if(i==m-1 &&  j== n-1){
            return 1;
        }
        if(t[i][j]!= -1){
            return t[i][j];
        
        }
        int right = solve(i,j+1);
   int down = solve(i+1,j);
        return t[i][j]=right + down ;

}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        ///out of bound case 
       
       
          grid = obstacleGrid;
        m = grid.size();
        n = grid[0].size();
        if(grid[0][0]==1){
            return 0;
        }
        memset(t,-1,sizeof(t));
        return solve(0,0);
        
    }
};