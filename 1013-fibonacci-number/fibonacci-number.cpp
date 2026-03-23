
// int fibon(int n, vector<int>& dp)
// {
//     if(n <= 1)
//         return n;

//     if(dp[n] != -1)
//         return dp[n];

//     return dp[n] = fibon(n-1, dp) + fibon(n-2, dp);
// }

// 👉 Approach:

// ✅ Top-Down DP (Memoization)

// Recursion use hota hai
// dp[n] me results store hote hain
// Pehle problem solve → phir store

// int fib(int n) {
//     vector<int> dp(n+1, -1);
//     return fibon(n, dp);
// }


class Solution {
public:
    int fibon(int n , vector<int> &dp){
        if(n<=1){
            return n ;
        }
        if(dp[n]!=-1){
            return dp[n];
        
        }
        return dp[n]= fibon(n-1,dp)+fibon(n-2,dp);
    }
    int fib(int n) {
        vector<int>dp(n+1,-1);
        // return fibon(n,dp);
        if(n<= 1 ){
            return n ; 
        }
        dp[0]=0;
        dp[1]= 1;
        
        for(int i = 2;i<=n;i++){
dp[i]= dp[i-1]+dp[i-2];
        }
        return dp[n];
        
    }
};

// 👉 Approach:

// ✅ Bottom-Up DP (Tabulation)

// No recursion
// Start from base cases
// Build answer step by step