class Solution {
public:
    bool isPalindrome(string s) {
      int n=s.size();
      int begin=0;
      int end=n-1;
      while(begin<end){
        while(begin<end&&!isalnum(s[begin])){
            begin++;
        }
        while(begin<end&&!isalnum(s[end])){
            end--;
        }
        if(begin>=end) break;
        char first=tolower(s[begin]);
        char second=tolower(s[end]);
        if(first!=second)return false;
        begin++;
        end--;
        
      }
      return true;
    }
};