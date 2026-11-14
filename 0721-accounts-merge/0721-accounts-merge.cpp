class DisjointSet{
public:
    vector<int>parent;
    vector<int>size;
    int findUltimateParent(int v,vector<int>&parent){
        if(v==parent[v]){
            return v;
        }
        return parent[v]=findUltimateParent(parent[v],parent);
    }
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    void unionBySize(int u,int v){
        int u_parent=findUltimateParent(u,parent);
        int v_parent=findUltimateParent(v,parent);
        if(u_parent==v_parent)return ;
        if(size[u_parent]<=size[v_parent]){
            parent[u_parent]=v_parent;
            size[v_parent]=size[u_parent]+size[v_parent];
        }
        else {
            parent[v_parent]=u_parent;
            size[u_parent]=size[u_parent]+size[v_parent];
        }
    }

};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mp.find(accounts[i][j])!=mp.end()){
                    ds.unionBySize(i,mp[accounts[i][j]]);
                }
                else {
                    mp[accounts[i][j]]=i;
                }
            }
        }
        unordered_map<int,set<string>>temp;
        for(int i=0;i<n;i++){
            int root=ds.findUltimateParent(i,ds.parent);
            for(int j=1;j<accounts[i].size();j++){
                temp[root].insert(accounts[i][j]);
            }
        }
        vector<vector<string>>ans;
        for(auto &it:temp){
            int root=it.first;
            vector<string>curr;
            curr.push_back(accounts[root][0]);
            for(const string & email:it.second){
                curr.push_back(email);
            }
            ans.push_back(curr);
        }
        return ans;
    }
};