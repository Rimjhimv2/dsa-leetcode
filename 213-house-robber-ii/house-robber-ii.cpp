// class Solution {
// public:

// int t[101];
// int solve(vector<int>&nums,int i ,int n ){
//     if(i>n){
//         ///imp point yaha n ko include mat karna 
//         return 0;
//     }
//     if(t[i]!=-1){
//         return t[i];
//     }
//     int take = nums[i]+solve(nums,i+2,n);
//     int skip = solve(nums,i+1,n);
     
//      return t[i] = max(take,skip);

// }
//     int rob(vector<int>& nums) {
//        int n = nums.size() ;
//        //ab apke pass ek hi ghar hai 
//        if(n==1){
//         return nums[0];
//        }
//        if(n==2){
//         return max(nums[0],nums[1]);
//        }
//        memset(t,-1,sizeof(t));
//        ///case 1 
//        //oth house le rahe hai toh ham n-1th house nhi le paynge wo bhi eski adjacent mai hoga 
//        int take_0th_house = solve(nums,0,n-2);
//        //ab ham 0th house nahi le rahe toh last n-1th house le paynge 


//        //2 bar house robber 1 call karna hai toh t ko fir se declare kro 
//        memset(t,-1,sizeof(t));
//        int take_nth_house = solve(nums,1,n-1);
//        return max(take_0th_house,take_nth_house);
//     }
// };

//ques why we use here house robber 1 twice???


// ans“Because the houses are arranged in a circle, the first and last houses are adjacent. So we cannot rob both together. To handle this, we break the problem into two linear subproblems (House Robber I):

// Rob from index 0 to n-2 (exclude last house)
// Rob from index 1 to n-1 (exclude first house)
// Then we take the maximum of both results.”


///bottom up approch 

// like n house = 4 h
// 1 2 3 1 
// bottom up ke liye phle state deffine karo
// t[i]= profit when wehave i house 
// //matlab kitne paise chura paye jab hmare pass
// i houses hai 
//agar 0 house hhouse hai tooh 0 profit

// agar 1 house hai toh us house ka profit
// agar 2 house hai toh 2 option hai 1 house skip krdo toh use phle house ka profit lo 
// agar house ko liya hai toh 


 class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        // CASE 1: skip last house
        vector<int> t(n, 0);
        t[0] = nums[0];
        //ab yha 0 hi hai 
        t[1] = max(nums[0], nums[1]);
        //or yaha t[i]= max money chura liya till ith matlab agar t[1] hai toh max money till 1 tak kitna chura liya i mean 0 or 1 m se konsa max hai 

//ab 2 hai toh yaha toh current house ko lo ya skip kar rahe agar skip kar rahe toh usse phle house tak kitna max money stole kara haii
        for(int i = 2; i < n-1; i++){
            int take = nums[i] + t[i-2];
            //or agar us house ko le raha toh us ghar ka money and usse phle ke phle tak ka adjacent money 
            int skip = t[i-1];
            t[i] = max(take, skip);
        }
        int result1 = t[n-2];
        // 👉 “Index 0 se n-2 tak jo maximum paisa kama sakte hain, wo yaha stored hai.”
        

//👉 Kyunki last house skip kiya hai

        // CASE 2: skip first house


        t.assign(n, 0);
        //👉 DP array ko reset kar diya
//t[i] = max money till i
        t[1] = nums[1];
        //👉 Kyun?

//Humne 0th house skip kar diya
//Isliye first valid house = index 1

        for(int i = 2; i < n; i++){
            int take = nums[i] + t[i-2];
            int skip = t[i-1];
            t[i] = max(take, skip);
        }
        int result2 = t[n-1];
        //  👉 “Index 1 se n-1 tak jo maximum paisa kama sakte hain, wo yaha stored hai.”

        return max(result1, result2);
    }
};
//tc = O(n)
//sc = O(n)