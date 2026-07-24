class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long ans = 1;

        while(exp > 0) {
            if(exp & 1)
                ans = (ans*base) % MOD;

                base = (base * base) % MOD;
                exp >>= 1;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long evenPos = (n + 1)/2;
        long long oddPos = n/2;

        long long evenWays = power(5, evenPos);
        long long oddWays = power(4, oddPos);

        return (evenWays * oddWays) % MOD;
    }
};