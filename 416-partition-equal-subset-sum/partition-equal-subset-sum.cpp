class Solution {
public:

int t[201][20001];

bool solve(vector<int>& nums,int i , int target){

    if(target == 0){
        return true ;
    }

    if(i>=nums.size()){
        return false;
    }

    if(target<0){
        return false;
    }

    if(t[i][target] != -1 ){
        return t[i][target];
    }

    bool take = solve(nums,i+1,target - nums[i]);

    bool skip = solve(nums,i+1,target);

    return t[i][target] = take || skip;
}
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
int sum = 0 ;
        for(int x : nums){
            sum+=x;
        }

        if(sum%2 != 0){
            return false;
        }

        int target = sum/2;
        memset(t,-1,sizeof(t));

        return solve(nums,0,target);
    }
};