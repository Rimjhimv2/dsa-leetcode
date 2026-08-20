// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
        
//         int m = grid.size();
//         int n = grid[0].size();

//         vector<vector<int>> t(m, vector<int>(n, 0));

//         t[0][0] = grid[0][0];

//         // First row
//         for (int col = 1; col < n; col++) {
//             t[0][col] = grid[0][col] + t[0][col-1];
//         }

//         // First column
//         for (int row = 1; row < m; row++) {
//             t[row][0] = grid[row][0] + t[row-1][0];
//         }

//         // Remaining cells
//         for (int i = 1; i < m; i++) {
//             for (int j = 1; j < n; j++) {
//                 t[i][j] = grid[i][j] + 
//                           min(t[i-1][j], t[i][j-1]);
//             }
//         }

//         return t[m-1][n-1];
//     }
// };

//TC: O(m*n)
// SC: O(m*n)


class Solution {
 public:
 int m, n ;
 int t[201][201];
 int solve(int i , int j ,vector<vector<int>>& grid ){

    if(i== m-1 && j == n-1){
        return grid[i][j];
    }

    if(i>=m || j>=n){
        return INT_MAX;
    }

    if(t[i][j]!=-1){
        return t[i][j];
    }

    return t[i][j] = grid[i][j] + min(solve(i+1,j,grid), solve(i,j+1,grid));
 }
  int minPathSum(vector<vector<int>>& grid) {
m = grid.size();
n = grid[0].size();
   memset(t,-1,sizeof(t));
   return solve(0,0,grid);
  }
};