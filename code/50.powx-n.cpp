class Solution {
public:
    double myPow(double x, int n) {
        double res = pow1 (x, n);
        if (n < 0) return 1/res;
        return res;
    }

private:
    double pow1(double x, int n) {
        if (n == 0) return 1;
        if (n == 2) return x*x;
        if (n % 2) return pow1(pow1(x, n/2), 2)*x;
        return myPow(pow1(x, n/2), 2);
    }
};