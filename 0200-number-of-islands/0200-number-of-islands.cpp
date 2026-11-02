class Solution {
    void dfs(vector<vector<char>>&grid,int row,int col){
        if(row<0||row>=grid.size()||col<0||col>=grid[0].size())return ;
        grid[row][col]='0';
        int del_row[]={-1,0,1,0};
        int del_col[]={0,-1,0,1};
        for(int i=0;i<4;i++){
                int new_row=row+del_row[i];
                int new_col=col+del_col[i];
                if(new_row>=0&&new_col>=0&&
                new_row<grid.size()&&new_col<grid[0].size()&&
                grid[new_row][new_col]=='1') dfs(grid,new_row,new_col);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
        
    }
};