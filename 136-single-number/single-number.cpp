class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        //same element ke sath xor karo toh 0 aata hai 
        //0 ^ a = a
        // a ^ a = 0 

        //es ques mai ek array de raklha hai or hame find karna ki array mai kon sa esa element hai jo 1 baar aaya ho 

        int ans = 0; 

        // for(int x : nums){
        //     ans = ans ^ x ;

        // }

for(int i = 0 ; i< nums.size() ; i++){
    ans = ans ^  nums[i];
}

        return ans;
    }
};