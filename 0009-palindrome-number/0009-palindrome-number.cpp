class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        if(x==0)return true;
       int digits=log10(x)+1;
       int num=x;

       while(x!=0){
        int k=pow(10,digits-1);
        int firstDigit=x/k;
        int lastDigit=x%10;
        if(firstDigit!=lastDigit)return false;
        x=x-firstDigit*k;
        x=x/10;
        digits=digits-2;
       }
       return true;
    }
};