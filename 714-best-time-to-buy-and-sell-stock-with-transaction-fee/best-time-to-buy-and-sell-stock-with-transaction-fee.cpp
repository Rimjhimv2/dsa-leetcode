class Solution {
public:
int t[500001][2];
int solve(vector<int>& prices,int i , bool bought, int fee){

    if(i>= prices.size()){
        return 0;
    }
    if(t[i][bought]!=-1){
        return t[i][bought];
    }

    if(bought){
        return  t[i][bought] = max(prices[i]- fee + solve(prices,i+1,false,fee),solve(prices,i+1,true,fee));
    }

    return t[i][bought] = max(-prices[i]+ solve(prices,i+1,true,fee),solve(prices,i+1,false,fee));
}
    int maxProfit(vector<int>& prices, int fee) {
        
        memset(t,-1,sizeof(t));
        return solve(prices,0,false,fee);
        //0 se start kar rahe or abhi stock nahi hai 
    }
};