class Solution {
public:
int t[100001][3][2];
int solve(vector<int>& prices,int i,int transaction,bool bought){

    if(i == prices.size() || transaction == 0 ){
        return 0;
    }

    if(t[i][transaction][bought]!=-1){
        return t[i][transaction][bought];
    }

    if(bought){
        return t[i][transaction][bought] = max(prices[i] + solve(prices,i+1, transaction- 1, false),
        solve(prices,i+1, transaction,true));
    }

    return t[i][transaction][bought] = 
    max(-prices[i] + solve(prices, i+1,transaction,true), solve(prices,i+1,transaction,false));
}
    int maxProfit(vector<int>& prices) {
        
        memset(t,-1,sizeof(t));
        return solve(prices,0,2,false);
    }
};