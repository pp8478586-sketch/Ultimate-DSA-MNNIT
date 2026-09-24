class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>dp(n,0);
        for(int i=0;i<m;i++){
            dp[0]=1;
            for(int j=1;j<n;j++){
                int temp=dp[j];
                dp[j]=dp[j-1]+temp;
            }
        }
        return dp[n-1];
    }
};