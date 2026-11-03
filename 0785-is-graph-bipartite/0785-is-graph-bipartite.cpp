class Solution {
    bool dfs(vector<vector<int>>&graph,vector<int>&color,int node,int nextColor){
        if(nextColor==0){
            nextColor=1;
        }
        else{
            nextColor=0;
        }
        for(int i=0;i<graph[node].size();i++){
            if(color[graph[node][i]]!=-1){
                if(color[graph[node][i]]!=nextColor)return true;
            }
            else{
                color[graph[node][i]]=nextColor;
                if(dfs(graph,color,graph[node][i],nextColor))return true;
            }
        
        }
        return false;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=0;
                if(dfs(graph,color,i,0))return false;
            }
        }
        return true;

    }
};