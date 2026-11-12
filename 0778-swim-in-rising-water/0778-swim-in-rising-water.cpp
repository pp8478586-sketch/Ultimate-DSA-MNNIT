class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>time(n,vector<int>(n,INT_MAX));
        time[0][0]=grid[0][0];
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({grid[0][0],0,0});
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int currTime=curr[0];
            int row=curr[1];
            int col=curr[2];
            if(currTime>time[row][col])continue;
            for(int i=0;i<4;i++){
                int newRow=row+delRow[i];
                int newCol=col+delCol[i];
                if(newRow==0&&newCol==0)continue;
                if(newRow>=0&&newRow<n&&newCol>=0&&newCol<n){
                    if(currTime<time[newRow][newCol]){
                        int newTime=max(currTime,grid[newRow][newCol]);
                        pq.push({newTime,newRow,newCol});
                        time[newRow][newCol]=newTime;
                    }
                    if(newRow==n-1&&newCol==n-1){
                        return time[n-1][n-1];
                    }
                }
            }
        }
        return time[n-1][n-1];
    }
};