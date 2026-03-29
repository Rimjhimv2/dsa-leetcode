class Solution {
public:

int t[101];
int solve(vector<int>&nums,int i ,int n ){
    if(i>n){
        ///imp point yaha n ko include mat karna 
        return 0;
    }
    if(t[i]!=-1){
        return t[i];
    }
    int take = nums[i]+solve(nums,i+2,n);
    int skip = solve(nums,i+1,n);
     
     return t[i] = max(take,skip);

}
    int rob(vector<int>& nums) {
       int n = nums.size() ;
       //ab apke pass ek hi ghar hai 
       if(n==1){
        return nums[0];
       }
       if(n==2){
        return max(nums[0],nums[1]);
       }
       memset(t,-1,sizeof(t));
       ///case 1 
       //oth house le rahe hai toh ham n-1th house nhi le paynge wo bhi eski adjacent mai hoga 
       int take_0th_house = solve(nums,0,n-2);
       //ab ham 0th house nahi le rahe toh last n-1th house le paynge 


       //2 bar house robber 1 call karna hai toh t ko fir se declare kro 
       memset(t,-1,sizeof(t));
       int take_nth_house = solve(nums,1,n-1);
       return max(take_0th_house,take_nth_house);
    }
};

//ques why we use here house robber 1 twice???


// ans“Because the houses are arranged in a circle, the first and last houses are adjacent. So we cannot rob both together. To handle this, we break the problem into two linear subproblems (House Robber I):

// Rob from index 0 to n-2 (exclude last house)
// Rob from index 1 to n-1 (exclude first house)
// Then we take the maximum of both results.”
