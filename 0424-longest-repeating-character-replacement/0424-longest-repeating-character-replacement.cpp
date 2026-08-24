class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26,0);
        int maxLength=0;
        int begin=0;
        for(int i=0;i<s.size();i++){
            freq[s[i]-'A']++;
            while(i-begin+1-*max_element(freq.begin(),freq.end())>k){
                freq[s[begin]-'A']--;
                begin++;
            }
            maxLength=max(maxLength,i-begin+1);
        }
        return maxLength;
    }
};