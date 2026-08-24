class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26,0);
        int maxLength=0;
        int begin=0;
        int maxFreq=0;
        for(int i=0;i<s.size();i++){
            freq[s[i]-'A']++;
            
            maxFreq=max(maxFreq,freq[s[i]-'A']);
            while(i-begin+1-maxFreq>k){
                freq[s[begin]-'A']--;
                begin++;
            }
            maxLength=max(maxLength,i-begin+1);
        }
        return maxLength;
    }
};