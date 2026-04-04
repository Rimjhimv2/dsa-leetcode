// class Solution {
// public:
// int n ;
// //memoize karne ke liye 2 d vector lo 
//  vector<vector<int>>t ;
// int child1Count(vector<vector<int>>& fruits){
//     int count = 0;
//     for(int i = 0;i<n;i++){
//         count += fruits[i][i];
//         //yaha se mujhe diagonal element mil jaynge 

//     }
//     return count;
// }

// int child2Count(int i ,int j , vector<vector<int>>&fruits){
// // kaha kaha possibility hai eske jane ki 

// //base case 
// if(i>= n || j<0 || j>= n){
//     return 0;
// }
// if( i == n-1 &&  j == n-1){
//     return 0;
//     //as it is collected by someone so mAKE IT zero
// }
// /// most imp condition 
//  if( i == j || i>j){
//     return 0;
//  }

//  if( t[i][j] != -1 ){
//     return t[i][j];
//  }
// int bottomLeft = fruits[i][j] + child2Count(i+1,j-1,fruits);

// int bottomDown = fruits[i][j]+ child2Count(i+1,j,fruits);
// int bottomRight = fruits[i][j]+child2Count(i+1,j+1,fruits);

// return t[i][j]=  max({bottomLeft,bottomRight,bottomDown});
// }


// int child3Count(int i ,int j , vector<vector<int>>&fruits){
// // kaha kaha possibility hai eske jane ki 

// //base case 
// if(i>= n || j<0 || j>= n){
//     return 0;
// }
// if( i == n-1 &&  j == n-1){
//     return 0;
//     //as it is collected by someone so mAKE IT zero
// }
// /// most imp condition 
//  if( i == j || j>i){
//     return 0;
//  }
//  if( t[i][j] != -1){
//     return t[i][j];
//  }
// int upRight = fruits[i][j] + child3Count(i-1,j+1,fruits);

// int right = fruits[i][j]+ child3Count(i,j+1,fruits);
// int bottomRight = fruits[i][j]+child3Count(i+1,j+1,fruits);

// return t[i][j] = max({upRight,bottomRight,right});
// }


//     int maxCollectedFruits(vector<vector<int>>& fruits) {
//         n = fruits.size();

//         t.resize(n,vector<int>(n,-1));

        
//         //child 1 yaha par passs kara hai 
//         int c1 = child1Count(fruits);
//         //ab child 2 pass karo 
//         int c2 = child2Count(0,n-1,fruits);

//         int c3 = child3Count(n-1,0,fruits);

//         return c1 + c2 + c3 ;

//     }
// };

//QUE SM 3 CHILD HAI 
//1 CHILD TOP ROW KE LEFT CORNER M HAI 
//2ND CHILD TOP ROW KE RIGHT CORNER M HAI 
//3RD CHILD LAST ROW KE LEFT SIDE HAI 

//OR HAR CHILD KO N-1 SE JYADA MOVE NAHI KAR SAKTA TO REACH LAST ROW K RIGHT CORNER MAI 
// OR VO RETURN KARO KI TINO CHILD KITNA MAX FRUIT DAL SAKTE LAST ROW KE RIGHT CORNER M 

//CHILD 1 KHALI DIAGONAL HI CHALEGA
//CHILD 2  









//ab bottom up approch se 
//mik theory 
//recursion code = two para meters were changing 
//Dp array = 2d matrix 
//state defination 
//t[i][j] = maximum fruits collected when reached [i][j ] from sources.
//child1 = khali diagonal element hi cover krega 

//t[i][j]= maximum fruits collected till [1][2] from [0][n-1];

// ex t[1][2]= max fruits collected till [1][2] from [0][n-1];

//mujhe previous se curreent ka annswer nikalna hai 
//child 2 mai diagonal ke left nahi ja skkte ( matlab i hamesha j se chota hona chiye )

 class Solution {
public:
   int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
       vector<vector<int>> t(n, vector<int>(n, 0));

        int result= 0 ;
        for( int i = 0 ; i<n ; i++){
            result += fruits[i][i];
        }

        ////before proceding child2 and child 3 , nullify the cell which can not be visited by child 2 and child 3 
//jaha child 2 or 3 nhi pahuch skta wha 0 kardo 
        for(int i = 0 ; i< n ; i++){
            for(int j = 0; j<n;j++){
                //diagonal ke above wala i< j hota hai 
                if(i< j && i+j < n-1){
                    t[i][j] = 0; 
                }
                else if ( i> j && i+j < n-1){
                    t[i][j]= 0;
                }
                else{
                    t[i][j]= fruits[i][j];
                }
            }
        }


        // cells upper to diagonal : i< j 
        for( int i = 1; i< n ; i++){
            for(int j = i+1 ; j < n ; j++){
                t[i][j] += max({t[i-1][j-1],t[i-1][j],(j+1 < n  ) ? t[i-1][j+1] : 0});
            }
        }

        //child 3 

        for( int j = 1; j< n ; j++){
            for(int i = j+1 ; i < n ; i++){
                t[i][j] += max({t[i-1][j-1],t[i][j-1],(i+1 < n  ) ? t[i+1][j-1] : 0});
            }
        }

        return result + t[n-1][n-2] + t[n-2][n-1];
    }
};