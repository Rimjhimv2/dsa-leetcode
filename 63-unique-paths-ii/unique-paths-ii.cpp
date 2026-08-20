class Solution {
public:
     int t[101][101];
     int m , n;
     int solve(int i , int j , vector<vector<int>>& grid){

        if(i>=m || j>=n || i<0 || j<0 || grid[i][j] == 1){
            return false;
        }

        if(i==m-1 && j== n-1){
            return true;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        int right = solve(i,j+1,grid);
        int down = solve(i+1,j,grid);

        return  t[i][j] = right + down;
     }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       m= obstacleGrid.size();
       n= obstacleGrid[0].size();

       memset(t,-1,sizeof(t));
       return  solve(0,0,obstacleGrid);
    }
};