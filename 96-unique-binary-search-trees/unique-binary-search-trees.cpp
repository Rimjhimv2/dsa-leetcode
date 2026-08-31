class Solution {
public:
int t[20][20];
    int solve(int start , int end){
        int count = 0 ;
        
        if(start > end ){
            return 1 ;
        }

        if(t[start][end]!= -1){
            return t[start ][end];
        }

        for ( int  i = start ; i <= end ; i++){
            int left_bst = solve (start , i-1);
            int right_bst = solve(i+1, end);
            count+= (left_bst * right_bst);

        }
        return  t[start][end] = count;
    }
    int numTrees(int n) {
        memset(t,-1,sizeof(t));
        return solve(1,n);
    }
};