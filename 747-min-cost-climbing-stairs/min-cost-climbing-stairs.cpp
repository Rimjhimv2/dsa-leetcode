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





// class Solution {
//      public:
//  int ways(int n , vector<int>& cost,vector<int>&dp){
// if(n<=1){
//     return 0;
// }
// if(dp[n]!= -1){
//     return dp[n];
// }
//  return dp[n]=min(cost[n-1]+ways(n-1,cost,dp),
//    (cost[n-2]+ways(n-2,cost,dp)));
//  }
//    int minCostClimbingStairs(vector<int>& cost) {
//      int n = cost.size();
//     vector<int>dp(n+1,-1);
//     return ways(n,cost,dp);
    
//    }
// };


///////bottom up approach se solve kroo

// class Solution {
//         public:
 
 
//    int minCostClimbingStairs(vector<int>& cost) {
//      int n = cost.size();
//      vector<int>dp(n+1,0);
//      dp[0]=0;
//      dp[1]=0;
//      //Loop me cost[n-1] kyu nahi le rahe, cost[i-1] kyu lete hain?
// //🧠 Simple answer:
// //👉 Kyuki i current stair hai
// //👉 aur n last stair hai
//      for(int i = 2;i<=n;i++){
//         dp[i]=min(cost[i-1]+dp[i-1],
//   (cost[i-2]+dp[i-2]));
//  }
     
   
//      return dp[n];
    
//    }
// };


//////space optimization

class Solution {
        public:
 
 
   int minCostClimbingStairs(vector<int>& cost) {
     int n = cost.size();
    
     int curr;
     int prev=0;
     int prev2 = 0;
     //Constraints:

//2 <= cost.length <= 1000
//constarints 2 se start hai esliye yaha for loop mai koi error nahi aay a
     for(int i = 2;i<=n;i++){
        curr = min(prev+cost[i-1],
        prev2+cost[i-2]);
        prev2 = prev;
        prev = curr;
     }
     //👉 “This is a DP problem optimized from O(n) space to O(1) by tracking only the last two states.”
      return curr;
    
   }
};
