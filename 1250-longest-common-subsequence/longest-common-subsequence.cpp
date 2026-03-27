class Solution {
public:
int t[1001][1001];
int m,n;
int solve ( string&s1,string &s2,int i , int j ){
    if(i>= m || j>= n){
        return 0;
    }
    if(t[i][j] != -1){
        return t[i][j];
    }
    if(s1[i]==s2[j]){
        return  t[i][j] = 1+solve(s1,s2,i+1,j+1);
    }
    return t[i][j] = max(solve(s1,s2,i+1,j),solve(s1,s2,i,j+1));
}
    int longestCommonSubsequence(string text1, string text2) {
        //recursion ke time 2 variable change ho rahe toh hame dp lena hoga vo 2d dp hoga for i and j ke liye 
        memset(t , -1 , sizeof(t));
        m = text1.size();
         n= text2.size();
        return solve(text1,text2,0,0);
    }
};
//Feature	Substring	Subsequence
//Continuity	✅ Must be continuous	❌ Not required
//Skipping	❌ Not allowed	✅ Allowed


///why we use dp in this problem??
//👉 Overlapping Subproblems

//Same states repeat again and again.

////Example:

// Strings: "abcde" and "ace"

// You will compute:

// f(2,2) again and again
// f(3,2) again and again

//kya kar rahe 
//agar equal ho rah a char toh ham +1 ka rahe 
//or agar nahi ho rah toh 2 case ban rahe ek ist string se 1st letter hatao and 2nd mai 2nd string se pic hata o

// 👉 This leads to:

// ⏱️ Time Complexity: O(2^n) (very slow)