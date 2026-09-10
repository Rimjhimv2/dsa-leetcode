class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int low = 0 ; 
        int high = n-1;
        while(low <= high){
            int mid = low + (high - low )/2;
            if(nums[mid] == target ){
                return mid;
            }
            //check left part is sorted or not 
            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target <= nums[mid]){
                    //loww mia milega
                    high = mid-1;
                }
                else{
                    low = mid + 1;
                }
            }
            else{

                if(nums[mid] <= target && target <= nums[high]){
                    //target lies in the right half sso left will  be eliminated
                    low = mid + 1;
                    
                }
                else{
                    high = mid-1;
                }
            }
        }

           return -1;
    }
};