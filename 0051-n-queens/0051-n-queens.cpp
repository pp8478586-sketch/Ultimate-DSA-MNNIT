class Solution {
    void helper(vector<bool>&diag1,vector<bool>&diag2,vector<bool>&col,int k,vector<string>temp,vector<vector<string>>&ans,int n){
        if(k==n){
            ans.push_back(temp);
            return ;
        }
        for(int i=0;i<n;i++){
            string st(n,'.');
            if(diag1[k-i+n-1]&&diag2[k+i]&&col[i]){
                st[i]='Q';
                temp.push_back(st);
                diag1[k-i+n-1]=false;
                diag2[k+i]=false;
                col[i]=false;
                helper(diag1,diag2,col,k+1,temp,ans,n);
                diag1[k-i+n-1]=true;
                diag2[k+i]=true;
                col[i]=true;
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<bool>diag1(2*n,true);
        vector<bool>diag2(2*n,true);
        vector<bool>col(n,true);
        vector<vector<string>>ans;
        vector<string>temp;
        helper(diag1,diag2,col,0,temp,ans,n);
        return ans;
    }
};