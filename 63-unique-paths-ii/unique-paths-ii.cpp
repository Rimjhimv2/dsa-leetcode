// class Solution {
// public:
// int t[101][101];
// int m,n;
// vector<vector<int>>grid;
// int solve(int i , int j ){
// if(i<0 || i>=m || j<0 || j>=n){
//             return 0;
//         }
        
//         //phle obstackle check karo becoz destination par bhi blocked ho sjati hai esliye first check block condtion then check sucess case 
//         if(grid[i][j]==1){
//             return t[i][j] = 0;
//         }
//         ///success acse 
//         if(i==m-1 &&  j== n-1){
//             return 1;
//         }
//         if(t[i][j]!= -1){
//             return t[i][j];
        
//         }
//         int right = solve(i,j+1);
//    int down = solve(i+1,j);
//         return t[i][j]=right + down ;

// }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         ///out of bound case 
       
       
//           grid = obstacleGrid;
//         m = grid.size();
//         n = grid[0].size();
//         if(grid[0][0]==1){
//             return 0;
//         }
//         memset(t,-1,sizeof(t));
//         return solve(0,0);
        
//     }
// };
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        vector<vector<int>> grid = obstacleGrid;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> t(m, vector<int>(n, 0));

        // start blocked
        if (grid[0][0] == 1) return 0;

        // first cell
        t[0][0] = 1;

        /// first row
        for (int col = 0; col < n; col++) {
            if (grid[0][col] == 1) {
                t[0][col] = 0;
            }
            else if (col == 0) {
                t[0][col] = 1;
            }
            else {
                t[0][col] = t[0][col - 1];  // ✅ FIX
            }
        }

        /// first column
        for (int row = 0; row < m; row++) {
            if (grid[row][0] == 1) {
                t[row][0] = 0;
            }
            else if (row == 0) {
                t[row][0] = 1;
            }
            else {
                t[row][0] = t[row - 1][0];  // ✅ FIX
            }
        }

        /// remaining grid
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j] == 1) {
                    t[i][j] = 0;
                } else {
                    t[i][j] = t[i - 1][j] + t[i][j - 1];
                }
            }
        }

        return t[m - 1][n - 1];
    }
};