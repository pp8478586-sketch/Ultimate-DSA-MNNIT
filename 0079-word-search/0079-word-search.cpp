class Solution {
    bool helper(vector<vector<char>>&board,string &word,int i,int j,int idx,int m,int n,vector<vector<int>>&visited){
        if(idx==word.size()){
            return true;
        }
        if(i<0||j<0||i>=m||j>=n){
            return false;
        }
        if(visited[i][j]==1||board[i][j]!=word[idx]){
            return false;
        }
        visited[i][j]=1;
        if(helper(board,word,i+1,j,idx+1,m,n,visited)||
           helper(board,word,i-1,j,idx+1,m,n,visited)||
           helper(board,word,i,j+1,idx+1,m,n,visited)||
           helper(board,word,i,j-1,idx+1,m,n,visited)){
            return true;
        }
        visited[i][j]=0;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(helper(board,word,i,j,0,m,n,visited)){
                    return true;
                }
            }
        }
        return false;
    }
};