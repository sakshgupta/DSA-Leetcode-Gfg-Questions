class Solution {
public:
    double myPow(double x, int n) {
        // 2^10 = (2*2)^5 = 4^5 (even)
        // 2^5 = (2)*2^4 (odd)
        long long temp = abs(n); // if neg then just return 1/ans
        double ans = 1.0;
        while(temp>0){
            if(temp%2 == 1){
                ans = ans * x;
                temp = temp-1;
            }
            else{
                x = x*x;
                temp = temp/2.0;
            }
        }
        if(n < 0) return 1/ans;
        return ans;
    }
};