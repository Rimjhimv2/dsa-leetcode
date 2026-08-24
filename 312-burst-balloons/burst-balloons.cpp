class Solution {
public:
int t[303][303];
int solve(vector<int>&nums,int l, int r){
    int result = INT_MIN;
    
    if(l+1 == r){
        return 0;
    }

    if(t[l][r]!=-1){
        return t[l][r];
    }

    for(int i = l+1 ; i<=r-1; i++){
        int cost = (nums[l] * nums[i] * nums[r]) + solve(nums,l,i) + solve(nums,i,r);

        result =max(result,cost);
    }
    return t[l][r] = result;
}

    int maxCoins(vector<int>& nums) {
        
        int n = nums.size();
        nums.insert(nums.begin(),1);
         nums.push_back(1);
        memset(t,-1,sizeof(t));
        return solve(nums,0,nums.size()-1);
    }
};