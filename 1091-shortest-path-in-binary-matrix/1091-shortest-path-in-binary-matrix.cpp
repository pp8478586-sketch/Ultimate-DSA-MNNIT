class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>visited(n,vector<int>(n,false));
        queue<pair<int,int>>q;
        if(grid[0][0]!=0)return -1;
        if(grid[n-1][n-1]!=0)return -1;
        q.push({0,0});
        int step=1;
        visited[0][0]=true;
        while(!q.empty()){
            int sz=q.size();
            for(int k=0;k<sz;k++){
                auto curr=q.front();
                q.pop();
                int row=curr.first;
                int col=curr.second;
                if(row==n-1 && col==n-1) return step;
                for(int i=-1;i<=1;i++){
                    for(int j=-1;j<=1;j++){
                        if(i==0 && j==0) continue;
                        int newRow=row+i;
                        int newCol=col+j;
                        if(newRow>=0&&newRow<n&&newCol>=0&&newCol<n&&grid[newRow][newCol]==0&&!visited[newRow][newCol]){
                            visited[newRow][newCol]=true;
                    
                            
                            q.push({newRow,newCol});
                        }
                    }
                }
            }
            step++;

        }
        return -1;
    }
    
};