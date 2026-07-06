class DisjointSet{
   
public:
     vector<int>rank,parent,size;
    // constructor for this class 
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    // find the element 
    int findUPar(int node){
        if(node==parent[node])
            return node;
        return parent[node]=findUPar(parent[node]);
    }
    // union by rank;
    void unionByRank(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v)return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else {
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }
    }
      // find the union by size
    void unionBySize(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v)return ;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
     
    }

};
class Solution{
public:
    int removeStones(vector<vector<int>>&stones){
        map<int,vector<int>>rowMap;
        map<int,vector<int>>colMap;
        int n=stones.size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            auto stone=stones[i];
            int row=stone[0];
            int col=stone[1];
            rowMap[row].push_back(i);
            colMap[col].push_back(i);
        }
        for(auto &it:rowMap){
            vector<int>vec=it.second;
            for(int i=1;i<vec.size();i++){
                ds.unionBySize(vec[i-1],vec[i]);
            }
        } 
         for(auto &it:colMap){
            vector<int>vec=it.second;
            for(int i=1;i<vec.size();i++){
                ds.unionBySize(vec[i-1],vec[i]);
            }
        } 
        int components=0;
        for(int i=0;i<n;i++){
            if(ds.findUPar(i)==i){
              components++;
            }
        }
        return n-components;
    }

};