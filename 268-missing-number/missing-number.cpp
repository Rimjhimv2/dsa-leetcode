class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        int ans = n;//3

        for(int i = 0 ; i< n ; i++){
            ans^=i;//0,1,2
            ans^=nums[i];//array ke number 

        }
        return ans ;
    }
};

// 3
// ^ 0
// ^ 3
// ^ 1
// ^ 0
// ^ 2
// ^ 1

//0 ^ 1 ^ 2 ^ 3
// ^
// 3 ^ 0 ^ 1
//ans = 2