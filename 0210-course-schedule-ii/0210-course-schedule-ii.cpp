class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<numCourses;i++){
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
        if(ans.size() != numCourses)
            return {};

        return ans;
    }
};