class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>distance(n,vector<int>(n,INT_MAX));
        for(int i=0;i<edges.size();i++){
            int first=edges[i][0];
            int second=edges[i][1];
            int wt=edges[i][2];
            distance[first][second]=distance[second][first]=wt;
        }
        // floyd warshall algo
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(distance[i][k]!=INT_MAX&&distance[k][j]!=INT_MAX){
                        distance[i][j]=min(distance[i][j],distance[i][k]+distance[k][j]);
                    }
                }
            }
        }
        int ans=0;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(i!=j&&distance[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(count<=mini){
                ans=i;
                mini=count;
            }
        }
        return ans;
    }
};