// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int n = nums.size();
//         int ans =0;
//         for(int i = 0 ; i<n ; i++){
//             int sum = 0;
//             for(int j = i ; j<n ; j++){
//                 sum+=nums[j];
//                 if(sum == goal){
//                     ans++;
//                 }

//             }
//         }
//         return ans;
//     }
// };


//  class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int n = nums.size();
//         int ans = 0; 
//         vector<int>prefix(n);
//         prefix[0]= nums[0];
//         for(int i = 1; i< n ; i++){
//             prefix[i]= prefix[i-1]+ nums[i];
//         }
//         for(int i=0; i< n ; i++){
//             int sum = 0;
//             for(int j = i ; j<n ; j++){
                

//                 if(i==0){
//                     if(prefix[j]==goal){
//                         ans++;
//                     }
//                 }
//               else{
//                 if(prefix[j]- prefix[i-1] == goal){
// ans++;
//                 }
//               }
             
//             }
//         }


// return ans;
//     }
//  };


  class Solution {
public:
     int numSubarraysWithSum(vector<int>& nums, int goal) {
         int n = nums.size();

         unordered_map<int,int>mp;
         int result = 0;
         int currSum =0;

         mp[0]=1;

         for(int x:nums){
            currSum+=x;

            int remainingSum = currSum-goal;

            if(mp.find(remainingSum)!=mp.end()){
                result += mp[remainingSum];
            }

            mp[currSum]++;
         }
return result;

    }
  };
