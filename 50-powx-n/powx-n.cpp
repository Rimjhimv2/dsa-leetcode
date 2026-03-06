class Solution {
public:

double solve(double x , long n ){
    if(n == 0) {
        return 1 ;
    }
    if(n < 0) {
        return solve ( 1/x , -n );
    }
    if(n % 2 == 0 ){
        return solve(x*x ,n/2);
    }
    return x* solve( x*x , (n-1)/2);
}
    double myPow(double x, int n) {
        return solve(x,(long)n);
    }
};


//Observation:
//1️⃣ Even Power
//Agar n even hai:
 
//Example:
//2^10
//= (2*2)^5
//= 4^5

//agar odd hai 
//2^5
//= 2 × (2^4)
//= 2 × (4^2)