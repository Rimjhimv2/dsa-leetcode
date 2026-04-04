class Solution {
public:
int n ;
//memoize karne ke liye 2 d vector lo 
 vector<vector<int>>t ;
int child1Count(vector<vector<int>>& fruits){
    int count = 0;
    for(int i = 0;i<n;i++){
        count += fruits[i][i];
        //yaha se mujhe diagonal element mil jaynge 

    }
    return count;
}

int child2Count(int i ,int j , vector<vector<int>>&fruits){
// kaha kaha possibility hai eske jane ki 

//base case 
if(i>= n || j<0 || j>= n){
    return 0;
}
if( i == n-1 &&  j == n-1){
    return 0;
    //as it is collected by someone so mAKE IT zero
}
/// most imp condition 
 if( i == j || i>j){
    return 0;
 }

 if( t[i][j] != -1 ){
    return t[i][j];
 }
int bottomLeft = fruits[i][j] + child2Count(i+1,j-1,fruits);

int bottomDown = fruits[i][j]+ child2Count(i+1,j,fruits);
int bottomRight = fruits[i][j]+child2Count(i+1,j+1,fruits);

return t[i][j]=  max({bottomLeft,bottomRight,bottomDown});
}


int child3Count(int i ,int j , vector<vector<int>>&fruits){
// kaha kaha possibility hai eske jane ki 

//base case 
if(i>= n || j<0 || j>= n){
    return 0;
}
if( i == n-1 &&  j == n-1){
    return 0;
    //as it is collected by someone so mAKE IT zero
}
/// most imp condition 
 if( i == j || j>i){
    return 0;
 }
 if( t[i][j] != -1){
    return t[i][j];
 }
int upRight = fruits[i][j] + child3Count(i-1,j+1,fruits);

int right = fruits[i][j]+ child3Count(i,j+1,fruits);
int bottomRight = fruits[i][j]+child3Count(i+1,j+1,fruits);

return t[i][j] = max({upRight,bottomRight,right});
}


    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();

        t.resize(n,vector<int>(n,-1));

        
        //child 1 yaha par passs kara hai 
        int c1 = child1Count(fruits);
        //ab child 2 pass karo 
        int c2 = child2Count(0,n-1,fruits);

        int c3 = child3Count(n-1,0,fruits);

        return c1 + c2 + c3 ;

    }
};

//QUE SM 3 CHILD HAI 
//1 CHILD TOP ROW KE LEFT CORNER M HAI 
//2ND CHILD TOP ROW KE RIGHT CORNER M HAI 
//3RD CHILD LAST ROW KE LEFT SIDE HAI 

//OR HAR CHILD KO N-1 SE JYADA MOVE NAHI KAR SAKTA TO REACH LAST ROW K RIGHT CORNER MAI 
// OR VO RETURN KARO KI TINO CHILD KITNA MAX FRUIT DAL SAKTE LAST ROW KE RIGHT CORNER M 

//CHILD 1 KHALI DIAGONAL HI CHALEGA
//CHILD 2  