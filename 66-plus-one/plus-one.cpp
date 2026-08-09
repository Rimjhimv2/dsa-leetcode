// class Solution {
// public:
//     vector<int> plusOne(vector<int>& digits) {
        
//         //last se hi start karna hi 
//         for(int i = digits.size() - 1 ; i>=0 ;i-- ){
//             if(digits[i] < 9 ){
//                 digits[i]++;
//                 return digits;
//             }

//             digits[i] = 0 ; 

//             //or ager sari hi gigits 9 hai toh digits ke begin mai 1 add karo 
            
//         }
//         digits.insert(digits.begin() , 1);

//             return digits;
//     }
// };

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        // Last digit se start karna hai
        for (int i = digits.size() - 1; i >= 0; i--) {

            // Agar digit 9 nahi hai
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            // Agar digit 9 hai, toh 0 kar do
            digits[i] = 0;
        }

        // Agar saare digits 9 the
        digits.insert(digits.begin(), 1);

        return digits;
    }
};