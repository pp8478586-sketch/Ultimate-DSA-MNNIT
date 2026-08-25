class Solution {
   
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>need;
        unordered_map<char,int>window;
        for(auto it:t){
            need[it]++;
        }
        int minLength=INT_MAX;
        int begin=0;
        int count=0;
        int minStart=0;
        for(int i=0;i<s.size();i++){
            window[s[i]]++;
            if(need.count(s[i])&&need[s[i]]==window[s[i]]){
                count++;
            }
            while(count==need.size()){
                if(minLength>i-begin+1){
                    minLength=i-begin+1;
                    minStart=begin;
                }
                if(need.count(s[begin])&&window[s[begin]]==need[s[begin]]){
                    count--;
                }
                window[s[begin]]--;
                begin++;
            }
            
        }
        if(minLength==INT_MAX)return "";
        return s.substr(minStart,minLength);
    }
};