class Solution {
    int helper(int a,vector<int>&dp){
        if(a==0)return 1;
        if(a==1)return 1;
        if(dp[a]!=-1)return dp[a];
        return dp[a]=helper(a-1,dp)+helper(a-2,dp);
    }
  
public:
    int climbStairs(int n){
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};