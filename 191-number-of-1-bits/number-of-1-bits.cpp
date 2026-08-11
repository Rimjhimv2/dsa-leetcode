class Solution {
public:
    int hammingWeight(int n) {
        
        int count = 0 ; 
        //n ko binary mai convert karo 
        //fir usko 1 ke sathh and operation laga 
        //ageer last 1 aaya toh count ++ karenge 
          //and fir n ko right shift karenge 

          while(n!=0){
            if( n & 1){
                count ++;
            }
             n= n>>1;
          }
          return count ;
    }
};