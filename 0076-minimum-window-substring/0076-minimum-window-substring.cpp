class Solution {
    bool check(unordered_map<int,int>&mp1,unordered_map<int,int>&mp2){
        bool isValid=true;
        for(auto it:mp2){
            if(mp1[it.first]<it.second){
                // this is valid window 
                isValid=false;
            }    
        }
        return isValid;
    }
public:
    string minWindow(string s, string t) {
        int n=t.size();
        int m=s.size();
        string a="";
        if(n>m)return a;
        int begin=0;
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        for(int i=0;i<n;i++){
            mp2[t[i]]++;
        }
        int minStart=0;
        int minEnd=0;
        int minLength=INT_MAX;
        for(int i=0;i<m;i++){
            mp1[s[i]]++;
            if(check(mp1,mp2)){
                while(check(mp1,mp2)){
                    mp1[s[begin]]--;
                    begin++;
                }
                if(i-begin+1+1<minLength){
                    minStart=begin-1;
                    minEnd=i;
                    minLength=minEnd-minStart+1;
                }
            }
        }
        if(minLength==INT_MAX)return a;
        for(int i=minStart;i<=minEnd;i++){
            a.push_back(s[i]);
        }
        return a;
          
    }
};