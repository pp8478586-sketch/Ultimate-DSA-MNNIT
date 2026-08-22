class Solution {
    double temp(double x, long long n){
        double number=x;
        double ans=1;
        while (n>1){
            if(n%2==0){
                number=number*number;
                n=n/2;
            }
            else{
                ans=ans*number;
                n=n-1;
            }
        }
        return ans*number;
    }
public:
    double myPow(double x, int n) {
        long long  N=n;
        if(N==0)return 1;
        if(N<0){
            N=-N;
            return 1/temp(x,N);
        }
        if(N>0)return temp(x,N);
        return 0;
    }
        
};