class DisjointSet {
public:
    int noOfFree=0;
    vector<int>parent;
    vector<int>size;
    int findUltimateParent(int v,vector<int>&parent){
        if(v==parent[v])return v;
        return parent[v]=findUltimateParent(parent[v],parent);
    }
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n);
       
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
            
        }
    }
    bool find(int u, int v) {
        int u_uParent=findUltimateParent(u,parent);
        int v_uParent=findUltimateParent(v,parent);
        if(u_uParent!=v_uParent)return false;
        return true;
    }
    void unionBySize(int u, int v) {
        int u_uParent=findUltimateParent(u,parent);
        int v_uParent=findUltimateParent(v,parent);
        if(u_uParent==v_uParent){
            noOfFree++;
            return ;
        }
        if(size[u_uParent]<=size[v_uParent]){
            parent[u_uParent]=v_uParent;
            size[v_uParent]=size[u_uParent]+size[v_uParent];
        }
        else{
            parent[v_uParent]=u_uParent;
            size[u_uParent]=size[u_uParent]+size[v_uParent];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        for(int i=0;i<connections.size();i++){
            ds.unionBySize(connections[i][0],connections[i][1]);
        }
        vector<int>arr=ds.parent;
        int count=0;
        for(int i=0;i<n;i++){
            if(ds.findUltimateParent(i,ds.parent)==i){
                count++;
            }
        }
        int available=ds.noOfFree;
        if(count-1>available)return -1;
        return count-1;

    }
};