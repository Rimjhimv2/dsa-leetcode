// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         int n = nums.size();
//         int pivot = -1 ;
//         vector<int>prefix(n);
//         prefix[0]= nums[0];
//         for(int i  =1 ; i< n ; i++){
//             prefix[i]= prefix[i-1] + nums[i];
//         }
//         for(int i = 0 ; i <n ; i++){
//             int leftSum = (i==0)? 0 : prefix[i-1];
//             int totalSum = prefix[n-1];
//             int rightSum = totalSum - prefix[i];

//             if(leftSum == rightSum){
//                 pivot = i;
//             }
//         }

//         return pivot;
//     }
// };


 class Solution {
 public:
   int pivotIndex(vector<int>& nums) {
         int n = nums.size();
         int totalSum = 0;
         for(int x:nums){
            totalSum+=x;
         }

         int leftSum =0;
         for(int i = 0 ; i<nums.size(); i++){
  

           int rightSum = totalSum-leftSum-nums[i];
           if(leftSum == rightSum){
            return i;
           }

           leftSum+=nums[i];
         }
       

return -1;


    }
 };