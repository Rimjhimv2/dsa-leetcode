// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int count = 0;;
//         int n = nums.size();
//         for(int i = 0; i< n; i++){
//             int sum = 0;
//             for(int j = i ; j< n;j++){
//                 sum+= nums[j];
//                 if(sum == k ){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };



 class Solution {
 public:
    int subarraySum(vector<int>& nums, int k) {
unordered_map<int,int>mp;
int n = nums.size();
int cumSum = 0 ; 
mp.insert({0,1});
int result = 0 ; 
for(int i = 0 ; i< n ; i++){
    cumSum+=nums[i];
    if(mp.find(cumSum-k)!= mp.end()){
        result+=mp[cumSum-k];
    }

    
    mp[cumSum]++;

    
    }
   return result;

    }
 };
