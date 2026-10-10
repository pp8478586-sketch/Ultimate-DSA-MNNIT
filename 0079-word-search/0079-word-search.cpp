class Solution {
    bool helper(vector<vector<char>>& board,vector<vector<int>>&visited,string &word,int i,int j,int curr_ind,int m,int n,int size){
        if(curr_ind==size){
            return true;
        }
        if(i<0||j<0||i>=m||j>=n){
            return false;
        }
        if(visited[i][j]==1||board[i][j]!=word[curr_ind]){
            return false;
        }
        visited[i][j]=1;
        if(helper(board,visited,word,i+1,j,curr_ind+1,m,n,size)||
        helper(board,visited,word,i,j-1,curr_ind+1,m,n,size)||
        helper(board,visited,word,i-1,j,curr_ind+1,m,n,size)||
        helper(board,visited,word,i,j+1,curr_ind+1,m,n,size)){
            return true;
        }
        visited[i][j]=0;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        int k=word.size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(helper(board,visited,word,i,j,0,m,n,k)){
                    return true;
                }
            }
        }
        return false;
        
    }
};