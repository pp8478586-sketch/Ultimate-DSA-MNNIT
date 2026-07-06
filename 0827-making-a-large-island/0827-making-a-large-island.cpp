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
    int largestIsland(vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        DisjointSet ds(n*m);
        int dr[]={1,0,-1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int row=i;
                int col=j;
                if(grid[row][col]==1){
                    int node=row*m+col;
                    for(int k=0;k<=1;k++){
                        int nr=row+dr[k];
                        int nc=col+dc[k];
                       
                        if(nr>=0&&nr<n&&nc>=0&&nc<m&&grid[nr][nc]==1){
                            int adjNode=nr*m+nc;
                            ds.unionBySize(node,adjNode);
                        }
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    int row=i;
                    int col=j;
                    set<int>st;
                    int sz=1;
                    for(int k=0;k<4;k++){
                        int nr=row+dr[k];
                        int nc=col+dc[k];
                        if(nr>=0&&nr<n&&nc>=0&&nc<m&&grid[nr][nc]==1){
                            int adjNode=nr*m+nc;
                            int ultP=ds.findUPar(adjNode);
                            
                            if(st.find(ultP)==st.end()){
                                sz+=ds.size[ultP];
                                st.insert(ultP);
                            }

                        }
                    }
                    ans=max(ans,sz);
                }
                
                
            }
        }
        if(ans==0)return n*m;
        else return ans;
    }

};