// class Solution {
// public:
// int m,n;


// int t[101][101];
// int solve(int i , int j ){
//     if(i==m-1 || j == n-1){
//         return 1;
//     }
//     if(t[i][j]!= -1){

//         return t[i][j];
//     }
//     if(i<0 || i>=m || j<0 || j>=n){
//         return t[i][j] = 0;
//     }
//     int right = solve(i,j+1);
//     int down = solve(i+1,j);
//     return t[i][j]=right + down ;
    
// }
//     int uniquePaths(int m, int n) {
//         this->m = m;
//         this->n = n;
//         memset( t , -1, sizeof(t));
//         return solve(0,0);
        
//     }
// };
//⚡ Final Answer
//Complexity	Value
//ime	O(m × n)
//Space	O(m × n)


///bottom up approch 
// state defination

// t[i][j]= x => no of ways to reach [i][j
// fron [0][0]]

class Solution {
public:
  int uniquePaths(int m, int n) {

    vector<vector<int>>t(m,vector<int>(n));

    t[0][0]=1;
    ///fill 0th row 
    //yahi yaha row same hai col change hoga tof for loop lagaoo col ke liye 
    for(int col =1;col<n;col++){
        t[0][col]=1;
    }
    //fill oth col 
    for(int row = 1; row<m;row++){
        t[row][0]=1;
    }
    for(int i = 1;i<m;i++){
        for(int j = 1;j<n;j++){
            t[i][j]=t[i-1][j] + t[i][j-1];
        }
    }
    return t[m-1][n-1];

  }
};