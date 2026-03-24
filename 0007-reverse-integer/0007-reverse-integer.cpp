class Solution {
public:
    int reverse(int x) {
        int reverseint=0;
        int k;
        while(x!=0){
            k=x%10;
            x=x/10;
            if (reverseint > INT_MAX/10 || reverseint < INT_MIN/10)
                return 0;
            reverseint=reverseint*10+k;
        }
        return reverseint;
        
    }
};