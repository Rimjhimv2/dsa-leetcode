// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int count = 0 ;
//         int candidate;

//         for(int x: nums){
//             if(count == 0 ){
//                 candidate = x;
//             }

//             if(x == candidate){
//                 count++;
//             }
//             else{
//                 count--;
//             }
//         }
//         return candidate;

//     }
// };

 class Solution {
 public:
    int majorityElement(vector<int>& nums) {
 unordered_map<int,int>mp;
   for(int x: nums){
    mp[x]++;
   }
   for(auto it: mp){
    if(it.second > nums.size()/2){
          return it.first;
    }
   }


return -1;
    }
 };
