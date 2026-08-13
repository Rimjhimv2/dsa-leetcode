class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 0 ; 

        for(int i = 0 ; i<= n ; i++){
            ans^=i;//0,1,2
            
        }
        for(int num : nums){
            ans^= num;
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