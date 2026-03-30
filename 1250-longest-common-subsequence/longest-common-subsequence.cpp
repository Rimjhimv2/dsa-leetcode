// class Solution {
// public:
// int t[1001][1001];
// int m,n;
// int solve ( string&s1,string &s2,int i , int j ){
//     if(i>= m || j>= n){
//         return 0;
//     }
//     if(t[i][j] != -1){
//         return t[i][j];
//     }
//     if(s1[i]==s2[j]){
//         return  t[i][j] = 1+solve(s1,s2,i+1,j+1);
//     }
//     return t[i][j] = max(solve(s1,s2,i+1,j),solve(s1,s2,i,j+1));
// }
//     int longestCommonSubsequence(string text1, string text2) {
//         //recursion ke time 2 variable change ho rahe toh hame dp lena hoga vo 2d dp hoga for i and j ke liye 
//         memset(t , -1 , sizeof(t));
//         m = text1.size();
//          n= text2.size();
//         return solve(text1,text2,0,0);
//     }
// };

// You have a DP table:

// t[i][j]

// Total possible states = m × n

// 👉 Each state (i, j) is computed only once due to memoization



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




////now move into  bottom. up approch 
//here yaha par hame t[m][n] yaha return karna hai toh t[m+1][n+1] array return karnege 

 class Solution {
public:
int longestCommonSubsequence(string s1, string s2) {
    int m = s1.length();
int n = s2.length();
 vector<vector<int>> t(m+1, vector<int>(n+1));
//    2D table banayi (m+1) × (n+1)
// 👉 t[i][j] store karega:

// LCS length of s1[0...i-1] and s2[0...j-1]
    //ab 1st colum ko 0 karna hai yani 0 col ko fix karo row ko change karti jao for loop likho row ke liye 

    for(int row = 0;row< m+1;row++){
        t[row][0]=0;
    }
    //base case 
    for(int col= 0;col< n+1;col++){
        t[0][col]=0;
    }
    //base case 

    // ab baki vaalue fill karo matrix mai 
    for( int i = 1 ; i< m+1;i++){
        for(int j = 1 ; j<n+1;j++){
            if(s1[i-1] == s2[j-1]){
                t[i][j]= 1 + t[i-1][j-1];
                //"Match mila → purane answer me 1 add kar do"
            }
            else{
                t[i][j] =  max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    ///ab hame print bhi karna ahi 
    string lcs = "";
//     🚶 Backtracking ka idea

// Jab tum LCS string banana chahte ho:

// 👉 Tum start karte ho jahan final answer hai

// ✔️ Isliye:

int i = m;
int j = n;
    
    while   (i >0 && j>0){
             if(s1[i-1] ==s2[j-1]){
                lcs.push_back(s1[i-1]);
                //diagonally dekh rahe
                i--;
                j--;
             }
             else{
                if(t[i-1][j]>t[i][j-1]){
                    i--;
                }
                else{
                    j--;
                }
             }
    }
    reverse(begin(lcs),end(lcs));
    return t[m][n];

}
 };

//  Overall kya kar raha hai code?

// 👉 Yeh code 2 kaam kar raha hai:

// LCS ki length nikal raha hai (DP se)
// LCS string bhi bana raha hai (backtracking se)