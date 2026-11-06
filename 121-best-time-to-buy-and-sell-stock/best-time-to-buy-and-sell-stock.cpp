class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minprice = INT_MAX;
        int max_profit = 0;
        int n = prices.size();

        for(int i = 0 ; i < n ; i++){
           minprice = min(minprice,prices[i]);
           int profit = prices[i] - minprice;
           max_profit = max(max_profit, profit);
        }
        return max_profit;
    }
};