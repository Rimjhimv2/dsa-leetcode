class Solution {
public:
    int minBitFlips(int start, int goal) {
        

        int x = start ^ goal;
        int count = 0 ; 
        while(x>0){
            if(x & 1 ){
                //agaer 1 hoga toh true hoga toh loop chalega
                count++;
            }
            x = x>>1;
        }
        return count;
    }
};

//TC: O(log(max(start, goal)))
//SC: O(1)