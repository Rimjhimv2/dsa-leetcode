class Solution {
public:
int t[5001][2];
int solve(vector<int>& prices,int i,bool bought){

   if(i >= prices.size()){
        return 0 ;
    }
    if(t[i][bought]!=-1){
        return t[i][bought];
    }

    if(bought){
        return t[i][bought] =  max(prices[i] + solve(prices,i+2,false),solve(prices,i+1,true));
    }

    return  t[i][bought] = max(-prices[i] + solve(prices,i+1,true),solve(prices,i+1,false));
}
    int maxProfit(vector<int>& prices) {
        memset(t,-1,sizeof(t));
        return solve(prices,0,false);
    }
};