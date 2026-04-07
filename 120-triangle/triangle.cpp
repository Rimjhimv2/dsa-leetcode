// class Solution {
// public:
//     int n;
//     int t[201][201];

//     int solve(vector<vector<int>>& triangle, int row, int col) {

//         if (row == n - 1) {
//             return triangle[row][col];
//         }

//         if (t[row][col] != -1) {
//             return t[row][col];
//         }

//       int minPath = triangle[row][col] + min(solve(triangle,row+1,col),solve(triangle,row+1,col+1));

//         return t[row][col] = minPath;
//     }

//     int minimumTotal(vector<vector<int>>& triangle) {
//         n = triangle.size();
//         memset(t, -1, sizeof(t));
//         return solve(triangle, 0, 0);
//     }
// };


//intution 

//jab ham last row mai pahuch gaye hai to 
//to hame us value to return kar rahe 

// min sum nikalo 
//us value ko add kro or min nikalo 



//////now method 2 
//state defination 
//t[row][col]= min path sum from [row][col] to bottom of the triangle.


//ab last row mai kya 
// jo bhi value hai usko return krdo

//yani t[n-1][col]
//or ham last se start kar rahe 
///or last se uper jaynge 


// class Solution{
//     public:

//      int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();

//         vector<vector<int>>t = triangle;
//         //space bhi n^2 le lia hai 
//         for(int row = n-2 ; row>=0;row--){
//             for(int col = 0 ; col<=row ; col++){

//                 //2 for loop hai hai to yaha O(n^2);
//                 t[row][col] = t[row][col] + min( t[row+1][col] , t[row+1][col+1]);

//             }
//         }
//         return t[0][0];
// }
// };



class Solution{
    public:

     int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<int>t = triangle[n-1];
        //space bhi n^2 le lia hai 
        for(int row = n-2 ; row>=0;row--){
            for(int col = 0 ; col<=row ; col++){

                //2 for loop hai hai to yaha O(n^2);
                t[col] = triangle[row][col] + min( t[col] , t[col+1]);

            }
        }
        return t[0];
}
};
