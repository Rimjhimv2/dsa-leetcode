class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        int prev = -1;

        while(n>0){
        int curr = n&1; 
        // curr mai last value aagyi hai 
         // fir usko compare karenge last ans last second ki value ko 


        if(prev == curr){
              return false ; 
        }
        prev = curr ; 
        n=n>>1;
        //n >> 1 → n ko half karta hai → baar-baar half karne mein log n steps lagte hain.
        //tc = O(logn) and sc = O(1);
        }

        return true ; 
    }
};