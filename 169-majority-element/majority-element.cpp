// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         map<int , int> mp;

//         for(int i = 0 ; i< n ; i++){
//             mp[nums[i]]++;
           

//         }
//        for( auto it : mp){
//           if(it.second > n/2){
//             return it.first;
//           }
//        }
//        return -1;
//     }
// };\



 class Solution {
 public:
    int majorityElement(vector<int>& nums) {
     int n = nums.size();

     int count = 0 ; 
     int candidate = 0 ;

     for( int x : nums){
        if(count == 0 ){
            candidate = x;
                   count = 1;
        }

        else if (  x == candidate ){
            count++;
        }

        else{
            count--;
        }
     }
      return candidate;
    }
 };
