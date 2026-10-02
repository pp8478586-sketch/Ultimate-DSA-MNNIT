class Solution {
    long long power(long long  k,long long  n,long long mod){
        if(n==0)return 1;
        long long half=power(k,n/2,mod);
        half=half%mod;
        half=(half*half)%mod;
        if(n%2==1){
            half=half*k;
        }
        return half;
    }
public:
    int  countGoodNumbers(long long n) {
        long long  ans=1;
        long long mod=1e9+7;
        long long  odd=n/2;
        long long  even=(n+1)/2;
        ans=ans*power(5,even,mod)%mod;
        ans=ans*power(4,odd,mod)%mod;
        return ans;

    }
};