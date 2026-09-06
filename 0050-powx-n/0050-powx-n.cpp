class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long pow = n;
        bool negative = false;
        if(pow < 0) {
            negative = true;
            pow = -1 * pow;
        }

        while(pow){
            if(pow % 2 == 0){
                x = x * x;
                pow = pow / 2;
            }
            else {
                ans = ans * x;
                pow = pow - 1;
            }
        }
        if(negative){
            ans = (double) (1.0)/ (double) ans;
        }
        return ans;
    }
};