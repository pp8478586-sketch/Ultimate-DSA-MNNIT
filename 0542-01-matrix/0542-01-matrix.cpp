class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    visited[i][j]=true;
                }
            }
        }
        int dist=1;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto curr=q.front();
                q.pop();
                int row=curr.first;
                int col=curr.second;
                int del_row[]={-1,0,1,0};
                int del_col[]={0,-1,0,1};
                for(int k=0;k<4;k++){
                    int new_row=row+del_row[k];
                    int new_col=col+del_col[k];
                    if(new_row>=0&&new_col>=0&&
                    new_row<n&&new_col<m&&!visited[new_row][new_col]){
                        mat[new_row][new_col]=dist;
                        visited[new_row][new_col]=true;
                        q.push({new_row,new_col});
                    }

                }
            }
            dist++;
        }
        return mat;
    }
};