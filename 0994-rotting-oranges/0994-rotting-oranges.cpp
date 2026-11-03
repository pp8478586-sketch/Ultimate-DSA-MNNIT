class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    fresh++;
                }

            }
        }
        int time=0;
        while(!q.empty()){
            int sz=q.size();
            int flag=0;
            for(int i=0;i<sz;i++){
                auto curr=q.front();
                q.pop();
                int row=curr.first;
                int col=curr.second;
                int del_row[]={-1,0,1,0};
                int del_col[]={0,1,0,-1};
                for(int k=0;k<4;k++){
                    int new_row=row+del_row[k];
                    int new_col=col+del_col[k];
                    if(new_row>=0&&new_col>=0&&
                    new_row<n&&new_col<m&&
                    grid[new_row][new_col]==1){
                        flag=1;
                        grid[new_row][new_col]=2;
                        q.push({new_row,new_col});
                        fresh--;
                    }
                }
            }
            if(flag==1){
                time++;
            }
        }
        return (fresh==0)?time:-1;
        
    }
};