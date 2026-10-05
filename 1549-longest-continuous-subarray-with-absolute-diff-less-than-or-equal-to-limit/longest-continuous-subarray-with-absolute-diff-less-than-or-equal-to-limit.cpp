class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();

       deque<int>decreasing;
       deque<int>increasing;

       int left = 0;
       int ans = 0 ;
       for(int right = 0 ; right<n ;right++){
           while(!decreasing.empty() && nums[decreasing.back() ] <= nums[right]) {
            decreasing.pop_back();
           }
decreasing.push_back(right);

             while(!increasing.empty() && nums[increasing.back() ] >= nums[right]) {
            increasing.pop_back();
           }
           increasing.push_back(right);

           //ab kya window ki condition khrab ho gayi toh left se shrink kro 
         while(nums[decreasing.front()] - nums[increasing.front()] > limit ){

           if(decreasing.front() == left){
             decreasing.pop_front();
           }

           if(increasing.front() == left){
             increasing.pop_front();
           }

              left++;
          
         }

            // Valid window ki length
            ans = max(ans, right - left + 1);


       }
       return ans;
    }
};