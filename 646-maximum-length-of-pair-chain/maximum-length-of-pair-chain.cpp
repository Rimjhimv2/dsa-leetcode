

class Solution {
public:
int n;
int t[2501][2501];
int solve(vector<vector<int>>& nums,int i ,int P){
    ///base case
    if(i>=n){
        return 0;
    }
//////❌ Agar tum directly use karo:
//t[i][P]

//Toh jab P = -1:

//t[i][-1]  ❌ INVALID

//👉 Crash / undefined behavior
//oor t ki limit bhi dekhna 
     if (t[i][P + 1] != -1) {   // FIXED
            return t[i][P + 1];
        }
    int take = 0;
    /////nums[i][0] > nums[P][1]

//Break karte hain:

//nums[i][0] → current pair ka start
//nums[P][1] → previous selected pair ka end
//or yaha 2d vector diya hai so esliye like hame curr ppair ka start value ko prev pair ke end value se compare karna 
    if(P==-1 || nums[i][0]>nums[P][1]){
        take = 1+solve(nums,i+1,i);
    }
    int skip = solve(nums,i+1,P);
    
    return t[i][P+1]=max(take,skip);
}
       int findLongestChain(vector<vector<int>>& pairs) {
      memset(t,-1,sizeof(t));
      n = pairs.size() ;
      ////////imp point
      sort(begin(pairs),end(pairs));
      return solve(pairs,0,-1) ;
    }
};