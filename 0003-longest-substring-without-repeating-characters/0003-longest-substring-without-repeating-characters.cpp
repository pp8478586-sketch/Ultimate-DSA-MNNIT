class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength=0;
        int begin=0;
        int length=0;
        vector<int>last(256,-1);
        for(int i=0;i<s.size();i++){
            if(last[s[i]]>=begin){
               begin=last[s[i]]+1; 
            }
            length=i-begin+1;
            last[s[i]]=i;
            maxLength=max(length,maxLength);
        }
        return maxLength;
    }
};