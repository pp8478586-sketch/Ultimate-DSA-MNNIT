class Solution {
    bool detectLoop(vector<vector<int>>&adj,vector<int>&visited,vector<int>&pathVisited,int node){
        if(visited[node]==1&&pathVisited[node]==1)return true;
        if(visited[node]==1)return false;
        visited[node]=1;
        pathVisited[node]=1;
        for(int i=0;i<adj[node].size();i++){
            if(detectLoop(adj,visited,pathVisited,adj[node][i]))return true;
        }
        pathVisited[node]=0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>visited(numCourses,0);
        vector<int>pathVisited(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(visited[i]!=1){
                if(detectLoop(adj,visited,pathVisited,i))return false;
            }
        }
        return true;


        
    }
};