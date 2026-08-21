// class Solution {
// public:

// int solve(vector<int>& coins,int i , int amount){
//     if(amount == 0 ){
//        return 1;
//     }
//     if(i== coins.size() ){
//         return 0;
//     }
//     if(coins[i] > amount){
//         solve(coins,i+1,amount);
//     }
//     int take = solve(coins,i,amount - coins[i]);

//     int skip = solve(coins,i+1, amount);

//     return take + skip ; 
// }
//     int coinChange(vector<int>& coins, int amount) {
//         return solve(coins,0,amount);
//     }
// };



class Solution {
public:
    int t[301][10001];

    int solve(vector<int>& coins, int i, int amount) {
        if (amount == 0)
            return 0;

        if (i == coins.size())
            return 1e9;

        if (coins[i] > amount)
            return solve(coins, i + 1, amount);

        if (t[i][amount] != -1)
            return t[i][amount];

        int take = 1 + solve(coins, i, amount - coins[i]);

        int skip = solve(coins, i + 1, amount);

        return t[i][amount] = min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(t, -1, sizeof(t));

        int ans = solve(coins, 0, amount);

        return ans == 1e9 ? -1 : ans;
    }
};