class Solution {
    void helper(int k,vector<int>temp,vector<vector<int>>&ans,vector<int>&nums,int n){
        ans.push_back(temp);
        for(int j=k;j<n;j++){
            if(j>k&&nums[j]==nums[j-1]){
                continue;
            }
            temp.push_back(nums[j]);
            helper(j+1,temp,ans,nums,n);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        vector<vector<int>>ans;
        int n=nums.size();
        helper(0,temp,ans,nums,n);
        return ans;
        
    }
};