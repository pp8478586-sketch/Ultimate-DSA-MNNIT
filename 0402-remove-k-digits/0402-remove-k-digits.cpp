class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        for(char c:num){
            while(!ans.empty()&&k>0&&ans.back()>c){
                ans.pop_back();
                k--;
            }
            ans.push_back(c);
        }
        while(k>0){
            ans.pop_back();
            k--;
        }
        int start=0;
        while(start<ans.size()-1&&ans[start]=='0')start++;
        string mainAns=ans.substr(start);
        return mainAns.empty()? "0":mainAns;
        
    }
};