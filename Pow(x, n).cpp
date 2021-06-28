class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        long long int nCopy = n;
        if(nCopy < 0) {
            nCopy = nCopy * -1;
        }
        while(nCopy) {
            if(nCopy%2 != 0) {
                res = res * x;
                nCopy = nCopy - 1;
            } else {
                x = x*x;
                nCopy = nCopy/2;
            }
        }
        if(n < 0) {
            res = (double)(1.0)/(double)(res);
        }
        return res;
    }
};