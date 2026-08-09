class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        //last se hi start karna hi 
        for(int i = digits.size() - 1 ; i>=0 ;i-- ){
            if(digits[i] < 9 ){
                digits[i]++;
                return digits;
            }

            digits[i] = 0 ; 

            //or ager sari hi gigits 9 hai toh digits ke begin mai 1 add karo 
            
        }
        digits.insert(digits.begin() , 1);

            return digits;
    }
};