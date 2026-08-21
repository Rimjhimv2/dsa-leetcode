class Solution {
public:
int solve(vector<int>& nums,int i , int currSum,int target){

    if(i == nums.size()){
        if(currSum == target){
            return 1;//we found 1 way to reach target 
        }
        else{
            return 0;
        }
    }

    int plus = solve(nums,i+1,currSum + nums[i], target);

    int minus = solve(nums,i+1,currSum - nums[i], target);

    return plus + minus; //total way to reah target 

}
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,0,0,target);
    }
};