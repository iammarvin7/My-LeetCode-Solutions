class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;
        bool neg = false;
        if(nn < 1) {
            nn *= -1;
            neg = true;
        }
        while(nn){
            if(nn%2){
                ans*= x;
                nn-=1;
            }
            else{
                x*=x;
                nn/=2;

            }
        }

        if(neg) return 1.0/ans;
        return ans;
    }
};