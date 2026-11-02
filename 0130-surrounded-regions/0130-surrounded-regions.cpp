class Solution {
    void dfs(vector<vector<char>>&board,int row,int col,vector<vector<int>>&visited){
        visited[row][col]=1;
        int del_row[]={0,1,-1,0};
        int del_col[]={-1,0,0,1};
        for(int i=0;i<4;i++){
            int new_row=row+del_row[i];
            int new_col=col+del_col[i];
            if(new_row>=0&&new_col>=0&&
            new_row<board.size()&&new_col<board[0].size()&&
            visited[new_row][new_col]==0&&board[new_row][new_col]=='O'){
                dfs(board,new_row,new_col,visited);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'&&visited[i][0]!=1){
                dfs(board,i,0,visited);
            }
            if(board[i][m-1]=='O'&&visited[i][m-1]!=1){
                dfs(board,i,m-1,visited);
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'&&visited[0][i]!=1){
                dfs(board,0,i,visited);
            }
            if(board[n-1][i]=='O'&&visited[n-1][i]!=1){
                dfs(board,n-1,i,visited);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'&&visited[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
        
        
    }
};