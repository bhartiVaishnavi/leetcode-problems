class Solution {
public:
    const long long MOD = 1e9 + 7;
    long long findpow(long long x, long long pow){
        long long ans = 1.0;
        while(pow){
            if(pow % 2 == 0){
                x = (x * x) % MOD;
                pow = pow / 2;
            }
            else{
                ans = (ans * x) % MOD;
                pow = pow - 1;
            }
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long even = (n + 1)/2;
        long long odd = n / 2;

        long long res = (findpow(5,even) * findpow(4, odd) ) % MOD;
        return res;
    }
};