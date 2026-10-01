// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
        
//         int n = nums.size();
//         int first = -1;
//         int second = -1;
//         for(int i = 0 ; i<n ; i++){
//             if(nums[i]== target){
//                 if(first == -1){
//                     first = i;
//                 }
//                 second = i;
//             }
            
//         }
       
       
//         return {first,second};
//     }
// };


 class Solution {
 public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
     int n = nums.size();
     //for lower bound i find the smallest index which is greater than or equal to target 

     int low = 0;
     int high = n-1;
     int first = n;

     while(low<=high){
        int mid = low + (high - low)/2;
        if(nums[mid] >= target){
            first = mid;
            high = mid-1;
        }
        else{
            low = mid +1;
        }
     }

     if(first == n || nums[first] != target)
    return {-1, -1};
low = 0 ;
high = n-1;
int last = n;
while(low<=high){
    int mid = low + (high - low)/2;
    if(nums[mid] > target){
        last = mid;
        high = mid-1;
    }
    else{
        low = mid+1;
    }
}
  
     return {first,last-1};

    }
 };
