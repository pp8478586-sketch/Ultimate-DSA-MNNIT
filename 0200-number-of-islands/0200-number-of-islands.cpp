class Solution {
    void dfs(vector<vector<char>>&grid,vector<vector<int>>&visited,int row,int col){
        if(row<0||row>=grid.size()||col<0||col>=grid[0].size())return ;
        visited[row][col]=1;
        int del_row[]={-1,0,1,0};
        int del_col[]={0,-1,0,1};
        for(int i=0;i<4;i++){
                int new_row=row+del_row[i];
                int new_col=col+del_col[i];
                if(new_row>=0&&new_col>=0&&
                new_row<grid.size()&&new_col<grid[0].size()&&
                grid[new_row][new_col]=='1'&&visited[new_row][new_col]!=1) dfs(grid,visited,new_row,new_col);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(visited[i][j]!=1&&grid[i][j]=='1'){
                    count++;
                    dfs(grid,visited,i,j);
                }
            }
        }
        return count;
        
    }
};