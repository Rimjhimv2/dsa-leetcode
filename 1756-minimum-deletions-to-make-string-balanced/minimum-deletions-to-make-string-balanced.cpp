class Solution {
public:
    int minimumDeletions(string s) {
         int bCount = 0 ; 
         int deleteCount = 0 ;

         for(int i = 0 ; i< s.size();i++){
            if(s[i]=='b'){
                bCount++;
            }
            else{

               deleteCount = min(deleteCount+1,bCount);
            }
         }
         return deleteCount;
    }
};

//tc = ek hi vbbaar string traverse kari hai toh ans = O(n);
//sc = sirf do variables hi use kare hai 