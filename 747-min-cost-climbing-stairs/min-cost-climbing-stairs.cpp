//////ye basic recursion se solve kra time complexity exponential m hogi or ye hme tle de raha hai 


// class Solution {
// public:
// int ways(int n , vector<int>& cost){
//     //base condition
//     if(n<=1){
//         return 0;
//     }
//     return min(cost[n-1]+ways(n-1,cost),
//     (cost[n-2]+ways(n-2,cost)));
// }
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         return ways(n,cost);
//     }
// };


class Solution {
     public:
 int ways(int n , vector<int>& cost,vector<int>&dp){
if(n<=1){
    return 0;
}
if(dp[n]!= -1){
    return dp[n];
}
 return dp[n]=min(cost[n-1]+ways(n-1,cost,dp),
   (cost[n-2]+ways(n-2,cost,dp)));
 }
   int minCostClimbingStairs(vector<int>& cost) {
     int n = cost.size();
    vector<int>dp(n+1,-1);
    return ways(n,cost,dp);
    
   }
};