// class Solution {
// public:
// int solve(vector<Int>&nums,int i ,int P){
//     ///base case
//     if(i>=n){
//         return 0;
//     }

//     if(t[i][P]!=-1){
//         return t[i][P];
//     }
//     int take = 0;
//     if(P==-1 || nums[i]>nums[P]){
//         take = 1+solve(nums,i+1,i);
//     }
//     int skip = solve(nums,i+1,P);
    
//     return t[i][P+1]=max(take,skip);
// }
//     int lengthOfLIS(vector<int>& nums) {
//       memset(t,-1,sizeof(t));
//       int n = nums.size() ;
//       retrun solve(nums,0,-1) ;
//     }
// };
class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {


int n = nums.size();
vector<int>t(n,1);
//sabko phle 1 iniliaze kra kyoki sab khud to subseq honge hi 
  int maxLis = 1;
for(int i = 0; i<n;i++){
    for(int j = 0;j<i;j++){
        if(nums[i]>nums[j]){
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