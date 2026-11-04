class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        // reverse the direction of the edges
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            indegree[i]=graph[i].size();
            for(int j=0;j<graph[i].size();j++){
                adj[graph[i][j]].push_back(i);
            }
        }
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                ans.push_back(i);
            }
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int i=0;i<adj[curr].size();i++){
                indegree[adj[curr][i]]--;
                if(indegree[adj[curr][i]]==0){
                    ans.push_back(adj[curr][i]);
                    q.push(adj[curr][i]);
                }
            }
        }
         sort(ans.begin(),ans.end());   
         return ans;     
    }
};