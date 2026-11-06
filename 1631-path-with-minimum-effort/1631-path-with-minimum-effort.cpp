class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>effort(n,vector<int>(m,INT_MAX));
        effort[0][0]=0;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int val=curr.first;
            int row=curr.second.first;
            int col=curr.second.second;
            if(val>effort[row][col])continue;
            int delRow[]={-1,0,1,0};
            int delCol[]={0,-1,0,1};
            for(int i=0;i<4;i++){
                int newRow=row+delRow[i];
                int newCol=col+delCol[i];
                if(newRow>=0&&newRow<n&&newCol>=0&&newCol<m){
                    int newEffort=max(val,abs(heights[row][col]-heights[newRow][newCol]));
                    if(newEffort<effort[newRow][newCol]){
                        pq.push({newEffort,{newRow,newCol}});
                        effort[newRow][newCol]=newEffort;
                    }
                }
            }
            
            
        }
        return effort[n-1][m-1];
    }
};