class Solution {
    void dfs(vector<vector<int>>&grid,int row,int col){
        grid[row][col]=0;
        int del_row[]={-1,0,1,0};
        int del_col[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int new_row=row+del_row[i];
            int new_col=col+del_col[i];
            if(new_row>=0&&new_col>=0&&
            new_row<grid.size()&&new_col<grid[0].size()&&
            grid[new_row][new_col]==1){
                dfs(grid,new_row,new_col);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                dfs(grid,i,0);
            }
            if(grid[i][m-1]==1){
                dfs(grid,i,m-1);
            }
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==1){
                dfs(grid,0,i);
            }
            if(grid[n-1][i]==1){
                dfs(grid,n-1,i);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
        
    }
};