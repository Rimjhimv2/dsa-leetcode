////////by using top down approch

// class Solution {
// public:
// int  count(int i,int n,vector<int>&dp){
//     if(i==n){
//         return 1;
    
//     }
//     if(i>n){
//         return 0;
//     }
//     if(dp[i]!=-1){
//         return dp[i];
//     }
//     return dp[i]= count(i+1,n,dp)+count(i+2,n,dp);
// }
//     int climbStairs(int n) {
//           vector<int> dp(n+2, -1); 
//        return count(0,n,dp); 
//     }
// };

//////now by using bottom up approach



// class Solution {
// public:
//     int climbStairs(int n) {

//         // Create DP array of size n+2 to avoid out-of-bounds
//         // dp[i] = number of ways to reach from step i to step n
//         vector<int> dp(n+2, 0);

//         // Base cases:
//         // If we are already at the top, there is 1 way (stay there)
//         dp[n] = 1;

//         // If we go beyond the top, there are 0 ways
//         dp[n+1] = 0;

//         // Fill the dp array in reverse (bottom-up approach)
//         for(int i = n-1; i >= 0; i--) {

//             // At each step, we can take 1 or 2 steps
//             // So total ways = ways from next step + ways from next to next step
//             dp[i] = dp[i+1] + dp[i+2];
//         }

//         // Answer: number of ways to start from step 0
//         return dp[0];
//     }
// };




// class Solution {
// public:
//     int climbStairs(int n) {
//         vector<int>dp(n+2,0);
//         int curr;
//         int next2 = 0;
//         int next  = 1 ;


//         for(int i=n-1;i>=0;i--){
//             curr = next+next2;
//             next2 = next;
//             next = curr;
//         }
        
//         return curr;
//             }
// };





///so abhi tak ham 0 se n ja rahe the 
//ab ham n se 0 jaynge 

// class Solution {
// public:
// int count(int n){
//  if(n<=1){
//             return 1;
//         }
//         return count(n-1)+count(n-2);
// }
//     int climbStairs(int n) {
  
    
//      return count(n);
       


//     }
// };


//now using top down approach
class Solution {
public:
    int count(int i, vector<int>& dp){
        // Base case
        if(i <= 1){
            return 1;
        }

        // Check if already computed
        if(dp[i] != -1){
            return dp[i];
        }

        // Store and return result
        return dp[i] = count(i-1, dp) + count(i-2, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return count(n, dp);
    }
};