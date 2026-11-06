class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<vector<int>>distance(n,vector<int>(k+2,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{src,0}});
        distance[src][0]=0;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int dis=curr.first;
            int city=curr.second.first;
            int stop=curr.second.second;
            if(stop>=k+1)continue;
            for(auto it:adj[city]){
                int newCity=it[0];
                int price=it[1];
                if(stop+1<=k+1&&dis+price<distance[newCity][stop+1]){
                    distance[newCity][stop+1]=dis+price;
                    pq.push({dis+price,{newCity,stop+1}});
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<=k+1;i++){
            ans=min(ans,distance[dst][i]);
        }
        return (ans==INT_MAX)?-1:ans;
    }
};