class Solution {
    void helper(vector<string>&ans,string temp,int k,int n,vector<vector<int>>&mp,string digits){
        if(k==n){
            ans.push_back(temp);
            return ;
        }
        vector<int>ch=mp[digits[k]-'0'];
        for(int x:ch){
            char y='a'+x;
            temp.push_back(y);
            helper(ans,temp,k+1,n,mp,digits);
            temp.pop_back();
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        vector<vector<int>>mp(10);
        int k=0;
        for(int i=2;i<=6;i++){
            for(int j=0;j<=2;j++){
                mp[i].push_back(k);
                k++;
            }
        }
        mp[7]={15,16,17,18};
        mp[8]={19,20,21};
        mp[9]={22,23,24,25};
        vector<string>ans;
        string temp;
        helper(ans,temp,0,n,mp,digits);
        return ans;
    }
};