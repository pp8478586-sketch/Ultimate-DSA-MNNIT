class Solution {
public:
    bool isPalindrome(string s) {
        string a;
        for(char c:s){
            if(isalnum(c)){
                c=tolower(c);
                a.push_back(c);
            }
        }
        int n=a.size();
        for(int i=0;i<n/2;i++){
            if(a[i]!=a[n-i-1]){
                return false;
            }
        }
        return true;
    }
};