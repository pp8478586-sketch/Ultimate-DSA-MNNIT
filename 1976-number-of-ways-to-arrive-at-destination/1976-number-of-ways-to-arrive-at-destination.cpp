class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long >distance(n,LLONG_MAX);
        vector<vector<int>>adj[n];
        vector<long long>ways(n,0);
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        distance[0]=0;
        const int mod=1e9+7;
        ways[0]=1;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            long long  dis=curr.first;
            int node=curr.second;
            if(distance[node]>dis)continue;
            for(auto it:adj[node]){
                int newNode=it[0];
                int wt=it[1];
                long long newWt=wt+dis;
                if(newWt<distance[newNode]){
                    pq.push({newWt,newNode});
                    ways[newNode]=ways[node];
                    distance[newNode]=newWt;
                }
                else if(newWt==distance[newNode]){
                    ways[newNode]=(ways[node]+ways[newNode])%mod;
                }
            }
        }
        return ways[n-1]%mod;

    }
};