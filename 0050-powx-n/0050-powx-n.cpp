class Solution {
public:
    double myPow(double x, int n) {
        long long exponent = n;

        if (exponent < 0) {
            x = 1.0 / x;
            exponent = -exponent;
        }

        double answer = 1.0;

        while (exponent > 0) {
            if (exponent % 2 == 1)
                answer *= x;

            x *= x;
            exponent /= 2;
        }

        return answer;
    }
};