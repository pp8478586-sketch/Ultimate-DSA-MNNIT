class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        if(m==1)dp[0][0]=grid[0][0];
        else{
            dp[0][m-1]=grid[0][0]+grid[0][m-1];
        }
        for(int i=1;i<n;i++){
            vector<vector<int>>temp(m,vector<int>(m,-1));
            for(int j1=0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){
                     for(int d1=-1;d1<=1;d1++){
                        for(int d2=-1;d2<=1;d2++){
                            int nj1=j1+d1;
                            int nj2=j2+d2;
                            if(j1!=j2){
                                if(nj1>=0&&nj1<m&&nj2>=0&&nj2<m&&dp[nj1][nj2]!=-1)temp[j1][j2]=max(temp[j1][j2],grid[i][j1]+grid[i][j2]+dp[nj1][nj2]);
                            }
                            else{
                                if(nj1>=0&&nj1<m&&nj2>=0&&nj2<m&&dp[nj1][nj2]!=-1)temp[j1][j2]=max(temp[j1][j2],grid[i][j1]+dp[nj1][nj2]);

                            } 
                        }
                     }
                }

            }
            dp=temp;
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};