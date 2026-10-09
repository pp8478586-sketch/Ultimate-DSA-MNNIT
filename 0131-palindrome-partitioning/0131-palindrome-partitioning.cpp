class Solution {
    bool isPalindrome(string &s,int i,int j){
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    void helper(vector<string>&temp,vector<vector<string>>&ans,int i,int n,string &s){
        if(i==n){
            ans.push_back(temp);
            return ;
        }
        for(int j=i;j<n;j++){
            if(isPalindrome(s,i,j)){
                temp.push_back(s.substr(i,j-i+1));
                helper(temp,ans,j+1,n,s);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        int n=s.size();
        helper(temp,ans,0,n,s);
        return ans;

    }
};