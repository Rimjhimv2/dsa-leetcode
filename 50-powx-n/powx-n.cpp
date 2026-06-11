class Solution {
public:
    double myPow(double x, int n) {

        long long N = n;

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double ans = 1.0;

        while (N > 0) {

            if (N % 2 == 1) {   // odd power
                ans *= x;
            }

            x *= x;    // square the base
            N /= 2;    // halve the exponent
        }

        return ans;
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