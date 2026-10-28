class Solution {
   
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0){
                    dp[i][j]=matrix[i][j];
                    continue;
                }
                else{
                    int up=1e9;
                    int left=1e9;
                    int right=1e9;
                    if(i-1>=0)up=dp[i-1][j];
                    if(i-1>=0&&j-1>=0)left=dp[i-1][j-1];
                    if(i-1>=0&&j+1<m)right=dp[i-1][j+1];
                    dp[i][j]=matrix[i][j]+min({left,up,right});
                }
                

            }
        }
        int ans=INT_MAX;
        for(int j=0;j<m;j++){
            ans=min(dp[n-1][j],ans);
            
        }
        return ans;
       
    }
};