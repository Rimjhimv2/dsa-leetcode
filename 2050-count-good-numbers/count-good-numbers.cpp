class Solution {
public:
    long long mod = 1000000007;

    long long power(long long x, long long n) {
        long long result = 1;

        while(n > 0) {
            if(n % 2 == 1) {
                result = (result * x) % mod;
            }

            x = (x * x) % mod;
            n /= 2;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;
        long long oddCount = n / 2;

        long long evenPart = power(5, evenCount);
        long long oddPart = power(4, oddCount);

        return (evenPart * oddPart) % mod;
    }
};