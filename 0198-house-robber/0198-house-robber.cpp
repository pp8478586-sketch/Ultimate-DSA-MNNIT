class Solution {
    int helper(vector<int>&nums,int k,vector<int>&dp){
        if(k==0)return nums[0];
        if(k<0)return 0;
        if(k==1)return max(nums[0],nums[1]);
        if(dp[k-1]==-1){
            dp[k-1]=helper(nums,k-1,dp);
        }
        if(dp[k-2]==-1){
            dp[k-2]=helper(nums,k-2,dp);
        }
        int pick=nums[k]+dp[k-2];
        int notPick=dp[k-1];
        return dp[k]=max(pick,notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return helper(nums,n-1,dp);
    }
};