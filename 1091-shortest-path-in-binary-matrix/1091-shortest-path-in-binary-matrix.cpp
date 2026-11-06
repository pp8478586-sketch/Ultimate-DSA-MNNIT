class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>distance(n,vector<int>(n,INT_MAX));
        if(grid[0][0]!=0)return -1;
        distance[0][0]=1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({1,{0,0}});
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int dis=curr.first;
            int row=curr.second.first;
            int col=curr.second.second;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int newRow=i+row;
                    int newCol=j+col;
                    if(newRow>=0&&newRow<n&&newCol>=0&&newCol<n&&grid[newRow][newCol]==0){
                        if(dis+1<distance[newRow][newCol]){
                            distance[newRow][newCol]=dis+1;
                            pq.push({dis+1,{newRow,newCol}});
                        }
                    }
                }

            }
        }
        return (distance[n-1][n-1]==INT_MAX)?-1:distance[n-1][n-1];
    }
};