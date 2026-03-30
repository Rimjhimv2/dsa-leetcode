// class Solution {
// public:
//     long long maxAlternatingSum(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<long>>t(n+1,vector<long>(2,0));
//         for(int i = 0; i<n+1;i++){

//             t[i][0]=max(t[i-1][1]-nums[i-1],t[i-1][0]);
//             t[i][1]=max(t[i-1][0]+ nums[i-1],t[i-1][1]);

//             //even subsequence bnana hai matlab last char add hoga phle wo odd tha 
//         }
//        return max(t[n][0],t[n][1]) ;
//     }
// };
// class Solution {
// public:
//     typedef long long ll;
//     int n;
//     vector<vector<ll>> dp;

//     ll solve(int idx, vector<int>& nums, bool flag) {
//         if(idx >= n) return 0;

//         if(dp[idx][flag] != -1) return dp[idx][flag];

//         // Skip current element
//         ll skip = solve(idx + 1, nums, flag);

//         // Take current element
//         ll val = nums[idx];
//         if(!flag) val = -val;

//         ll take = solve(idx + 1, nums, !flag) + val;

//         return dp[idx][flag] = max(skip, take);
//     }

//     long long maxAlternatingSum(vector<int>& nums) {
//         n = nums.size();
//         dp.assign(n, vector<ll>(2, -1)); // 2 states for flag: true/false
//         return solve(0, nums, true);      // start with positive
//     }
// };

 class Solution {
 public:
  long long maxAlternatingSum(vector<int>& nums) {

int n= nums.size();
vector<vector<long>> t(n + 1, vector<long>(2, 0));

for(int i = 1; i<n+1;i++){
    t[i][0]= max(t[i-1][1]-nums[i-1],t[i-1][0]);

    t[i][1]= max(t[i-1][0]+nums[i-1],t[i-1][1]);


}
        return( t[n][0],t[n][1]);
  }
 };

