// class Solution {
// public:
// int robbery(int i ,vector<int>& nums ){
//     if(i==0){
//         return nums[0];
//     }
//     if(i==1){
//         return max(nums[0],nums[1]);
//     }
//     return max(nums[i]+robbery(i-2,nums),
//     robbery(i-1,nums));
// }
//     int rob(vector<int>& nums) {
        
//         int n = nums.size();
//         /////n-1 isliye liya kyuki array 0-based indexing follow karta hai
//         return robbery(n-1,nums);
//     }
// };

//method 2 
// in the aboove code. tc = O(n) and sc = O(n) hai so i have to optimized this 

// ques how did i figure it out that it can be solved using constant space ??/

// class Solution{
//     public:
//     int rob(vector<int>&nums){
//         int n = nums.size();

//         if(n==1)
//         {
//             return nums[0];
//             //ek hi house hai 
//         }
//         //ab ek dp array t name se bnao or ek extra size ka 

//         vector<int>t(n+1);
//         t[0]= 0;
//         //ek bhi house consider nahi kara toh kisi ko nahi loot paynge 
//         t[1]= nums[0];
//        // 👉 sirf 1 house (index 0) consider kiya → paisa = nums[0]

//        //ab 2 house se leker n house slect kar sakte hai 

//        for(int i =2 ; i<= n ; i++){
//         int skip = t[i-1];
//         int take = nums[i-1] + t[i-2];
//         t[i] = max(skip,take);

//        }
//        return t[n];
//     }

// };

class Solution{
    public:
    int rob(vector<int>&nums){
        int n = nums.size();

        if(n==1)
        {
            return nums[0];
            //ek hi house hai 
        }
        //ab ek dp array t name se bnao or ek extra size ka 

        vector<int>t(n+1);
        int prevPrev= 0;
        //ek bhi house consider nahi kara toh kisi ko nahi loot paynge 
        int prev= nums[0];
       // 👉 sirf 1 house (index 0) consider kiya → paisa = nums[0]

       //ab 2 house se leker n house slect kar sakte hai 

       for(int i =2 ; i<= n ; i++){
        int skip = prev;
        int take = nums[i-1] + prevPrev;
        int temp = max(skip,take);
prevPrev = prev;
       prev= temp;
       }
       
       return prev;
    }

};