class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];

        int fast = nums[0];
        //abhi dono equal hi loop topp se fayeda nhi hoga 
        slow = nums[slow];
        fast = nums[nums[fast]];
        while(slow!= fast){
           slow = nums[slow];  
        fast = nums[nums[fast]];
        }
        slow = nums[0];
        while(slow!= fast){
             slow = nums[slow];
        fast =nums[fast];
        }


        
        return fast;

    }
};