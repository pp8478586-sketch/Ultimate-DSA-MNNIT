class Solution {
    void helper(int open ,int close,string curr,vector<string>&ans,int n){
        if(open==n&&close==n){
            ans.push_back(curr);
            return ;
        }
        if(open<n){
            curr.push_back('(');
            helper(open+1,close,curr,ans,n);
            curr.pop_back();
        }
        if(close<open){
            curr.push_back(')');
            helper(open,close+1,curr,ans,n);
            curr.pop_back();
        }

    }
public:

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string curr;
        helper(0,0,curr,ans,n);
        return ans;
    }
};