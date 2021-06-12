class Solution {
public:
    int divide(int dividend, int divisor) {
        long a = labs(dividend);
        long b = labs(divisor);
        long sign;
        if((dividend < 0) ^ (divisor < 0)) {
            sign = -1;
        } else {
            sign = 1;
        }
        if (b == 0 || dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        } else if (b == 1) {
             return sign * a;
        }
        long result = 0;
        int i = 0;
        while(a >= b) {
            i = 0;
            while(a >= b<<i) {
                a -= b<<i;
                result += 1<<i;
                i++;
            }
        }
        return (sign * result);
    }
};