

// class Solution {
// public:
// int n;
// int t[2501][2501];
// int solve(vector<vector<int>>& nums,int i ,int P){
//     ///base case
//     if(i>=n){
//         return 0;
//     }
// //////❌ Agar tum directly use karo:
// //t[i][P]

// //Toh jab P = -1:

// //t[i][-1]  ❌ INVALID

// //👉 Crash / undefined behavior
// //oor t ki limit bhi dekhna 
//      if (t[i][P + 1] != -1) {   // FIXED
//             return t[i][P + 1];
//         }
//     int take = 0;
//     /////nums[i][0] > nums[P][1]

// //Break karte hain:

// //nums[i][0] → current pair ka start
// //nums[P][1] → previous selected pair ka end
// //or yaha 2d vector diya hai so esliye like hame curr ppair ka start value ko prev pair ke end value se compare karna 
//     if(P==-1 || nums[i][0]>nums[P][1]){
//         take = 1+solve(nums,i+1,i);
//     }
//     int skip = solve(nums,i+1,P);
    
//     return t[i][P+1]=max(take,skip);
// }
//        int findLongestChain(vector<vector<int>>& pairs) {
//       memset(t,-1,sizeof(t));
//       n = pairs.size() ;
//       ////////imp point
//       sort(begin(pairs),end(pairs));
//       return solve(pairs,0,-1) ;
//     }
// };



/////bottom up approch 
class Solution {
public:
    int findLongestChain(vector<vector<int>>& nums) {


int n = nums.size();
sort(begin(nums),end(nums));
vector<int>t(n,1);
//sabko phle 1 iniliaze kra kyoki sab khud to subseq honge hi 
  int maxLis = 1;
  //1 esliye becoz har element khud mai subsequence hai hi esliye 
for(int i = 0; i<n;i++){
    for(int j = 0;j<i;j++){
        if(nums[i][0]>nums[j][1]){
            t[i]=max(t[i],t[j]+1);
            maxLis = max(maxLis,t[i]);
        }
    }
}

return maxLis;
//t[i]= lis end at ith index
//t[j]= j par end hone vala sabse baada subsequence kya hai 

//and t[j] kya hai j index par jake uski length dekhlo for agar value choti hai toh ham ek vaue add karke max dekhenge

  }
};