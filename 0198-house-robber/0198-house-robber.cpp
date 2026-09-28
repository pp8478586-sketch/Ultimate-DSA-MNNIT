class Solution {
    int helper(vector<int>&nums,int k,vector<int>&dp){
        if(k==0)return nums[0];
        if(k<0)return 0;
        if(dp[k]!=-1)return dp[k];
        int pick=nums[k]+helper(nums,k-2,dp);
        int notPick=helper(nums,k-1,dp);
        return dp[k]=max(pick,notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return helper(nums,n-1,dp);
    }
};