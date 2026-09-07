class Solution {
public:
    bool isPalindrome(int x) {
       int reverseNumber=0;
       int k=x;
       if(x<0)return false;
       while(k!=0){
            int temp=k%10;
            k=k/10;
            if(reverseNumber>INT_MAX/10||reverseNumber<INT_MIN/10)return 0;
            reverseNumber=reverseNumber*10+temp;
       } 
       if(reverseNumber==x)return true;
       return false;
    }
};