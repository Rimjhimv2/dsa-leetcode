// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
        
//     int profit = 0 ; 
//     for(int i = 1 ; i < prices.size(); i++)
//     {
//         if(prices[i] > prices[i-1]){
//             profit +=prices[i]- prices[i-1];
//         }
//     }
//     return profit;
//     }
// };

// "I use a greedy approach. Whenever the current day's price is greater than the previous day's price, I add that difference to the profit. This captures every profitable upward movement. The time complexity is O(n) and space complexity is O(1)."


class Solution {
public:
int t[300001][2];
int solve(vector<int>& prices,int i,bool bought){

   if(i >= prices.size()){
        return 0 ;
    }
    if(t[i][bought]!=-1){
        return t[i][bought];
    }

    if(bought){
        return t[i][bought] =  max(prices[i] + solve(prices,i+1,false),solve(prices,i+1,true));
    }

    return  t[i][bought] = max(-prices[i] + solve(prices,i+1,true),solve(prices,i+1,false));
}
         int maxProfit(vector<int>& prices) {
        memset(t,-1,sizeof(t));
        return solve(prices,0,false);
    }
};