class Solution {
public:
    string longestPalindrome(string s) {
        int start=0;
        int length=0;
        int n=s.size();
        int i=0;
        for(int i=0;i<n;i++){
            int left=i;
            int right=i;
            while(left>=0&&right<n&&s[left]==s[right]){
                if(length<right-left+1){
                    start=left;
                    length=right-left+1;
                }
                left--;
                right++;
            }
            left=i;
            right=i+1;
            while(left>=0&&right<n&&s[left]==s[right]){
                if(length<right-left+1){
                    start=left;
                    length=right-left+1;
                }
                left--;
                right++;
            }
           
        }
        return s.substr(start,length);
    }
};