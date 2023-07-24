class Solution {
public:
// for odd 2^5 = 2* (2)^4 here 2 is out answer and x remains same and x will dec by 1
// for even 2^10 = (2*2)^5 = 4^5 here x will double and n will get half
// this is called binary exponential and its a trick to find pow(x,n) in logn time
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