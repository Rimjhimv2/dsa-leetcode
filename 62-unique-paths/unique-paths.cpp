class Solution {
public:
int m,n;


int t[101][101];
int solve(int i , int j ){
    if(i==m-1 || j == n-1){
        return 1;
    }
    if(t[i][j]!= -1){

        return t[i][j];
    }
    if(i<0 || i>=m || j<0 || j>=n){
        return t[i][j] = 0;
    }
    int right = solve(i,j+1);
    int down = solve(i+1,j);
    return t[i][j]=right + down ;
    
}
    int uniquePaths(int m, int n) {
        this->m = m;
        this->n = n;
        memset( t , -1, sizeof(t));
        return solve(0,0);
        
    }
};