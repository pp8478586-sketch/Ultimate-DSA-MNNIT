class Solution {
    bool helper(vector<vector<bool>>&row,vector<vector<bool>>&col,vector<vector<char>>&ans,vector<vector<char>>&main_ans,vector<vector<vector<bool>>>&block,int k,int l ){
        if(k==9){
            main_ans=ans;
            return true;
        }
        if(l>=9){
            return helper(row,col,ans,main_ans,block,k+1,0);
            
        }
        if(ans[k][l]!='.'){
            return helper(row,col,ans,main_ans,block,k,l+1);
           
        }
        
        for(int i=1;i<=9;i++){
            int s1=(k/3);
            int s2=(l/3);
            if(row[k][i]&&col[l][i]&&block[s1][s2][i]){
                ans[k][l]=i+'0';
                row[k][i]=false;
                col[l][i]=false;
                block[s1][s2][i]=false;
                if(helper(row,col,ans,main_ans,block,k,l+1))
                    return true;
                ans[k][l]='.';
                row[k][i]=true;
                col[l][i]=true;
                block[s1][s2][i]=true;
            }
        }
        return false;
        
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>>ans=board;
        vector<vector<char>>main_ans;
        vector<vector<bool>>row(9,vector<bool>(10,true));
        vector<vector<bool>>col(9,vector<bool>(10,true));
        vector<vector<vector<bool>>>block(3,vector<vector<bool>>(3,vector<bool>(10,true)));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                     int num=board[i][j]-'0';
                    row[i][num]=false;
                    col[j][num]=false;
                    block[i/3][j/3][num]=false;
                }
               
            }
        }
        helper(row,col,ans,main_ans,block,0,0);
        board=main_ans;


        
    }
};