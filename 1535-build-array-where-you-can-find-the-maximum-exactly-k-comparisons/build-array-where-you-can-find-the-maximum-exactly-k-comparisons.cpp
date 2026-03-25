class Solution {
public:
    int N,M,K;
    int MOD=1e9+7;
    int t[51][51][101];
    int solve(int idx,int solveCost,int maxVal){
        if(idx==N){
            if(solveCost==K){
                return 1;
            }
            return 0;
        }
        if(t[idx][solveCost][maxVal]!=-1){
            return t[idx][solveCost][maxVal];
        }
        int result =0;
        
        for(int i=1;i<=M;i++){
            if(i>maxVal){
                result=(result+solve(idx+1,solveCost+1,i))%MOD;
            }
            else{
                result = (result+solve(idx+1,solveCost,maxVal))%MOD;
            }
        }
        return t[idx][solveCost][maxVal]= result% MOD;
    }
    int numOfArrays(int n, int m, int k) {   N = n;
    M=m;
    K=k;
                                          memset(t,-1,sizeof(t));
                                          return solve(0,0,0);
        
    }
};