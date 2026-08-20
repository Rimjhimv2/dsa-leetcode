class Solution {
public:

int t[101];
int solve(vector<int>& nums,int i , int n ){

if(i>=n){
    return 0;
}

if(t[i]!=-1){
    return t[i];
}
    int steal = nums[i] + solve(nums,i+2,n);

    int skip = solve(nums,i+1,n);

    return t[i] =  max(steal,skip);
}
    int rob(vector<int>& nums) {
        int n = nums.size();
       
        //base case ager 1 hi house ho toh sirf usme hi chori karo 
        if(n==1){
            return nums[0];
        }
 memset(t,-1,sizeof(t));
        int max1 = solve(nums,0,n-1);
        //first house ko liya toh last house skip
memset(t, -1, sizeof(t));
        int max2 = solve(nums,1,n);
        //first house ko skip kara and last wala liya 

        return max(max1,max2);
    }
};