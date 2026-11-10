class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>time(n+1,INT_MAX);
        vector<vector<int>>adj[n+1];
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        time[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int node=curr.second;
            int dis=curr.first;
            if(time[node]<dis)continue;
            for(auto it:adj[node]){
                int newNode=it[0];
                int wt=it[1];
                int newWt=wt+dis;
                if(newWt<time[newNode]){
                    time[newNode]=newWt;
                    pq.push({newWt,newNode});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            if(time[i]==INT_MAX){
                return -1;
            }
            ans=max(ans,time[i]);
        }
        return ans;
    }
};