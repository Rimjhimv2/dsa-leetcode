class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        

        int XORALL = 0 ; 
        for(int num : nums){
            XORALL ^= num ; 
        }

       long long diff = (long long)XORALL & (-(long long)XORALL);
        
        //diff mein sirf ek bit 1 hoti hai — jo unique numbers ko differentiate karti hai.

        int a = 0 ; 
        int b = 0 ; 


for (int num : nums) {

            if (num & diff) {
                a ^= num;
            } else {
                b ^= num;
            }
        }

        return {a, b};
    }
};