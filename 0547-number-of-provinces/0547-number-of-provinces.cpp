class Solution {
    void dfs(vector<vector<int>>&isConnected,vector<int>&visited,int node){
        visited[node]=1;
        for(int j=0;j<isConnected.size();j++){
            if(isConnected[node][j]==1&&visited[j]!=1){
                dfs(isConnected,visited,j);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans=0;
        int n=isConnected.size();
        vector<int>visited(n,0);
        for(int i=0;i<isConnected.size();i++){
            if(visited[i]==0){
                ans++;
                dfs(isConnected,visited,i);

            }
        }
        return ans;
        
    }
};