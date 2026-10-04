class Solution {
    void helper(int k,vector<int>temp,vector<vector<int>>&ans,vector<int>&nums,int n){
        if(k==n){
            ans.push_back(temp);
            return ;
        }
        // take it ;
        temp.push_back(nums[k]);
        helper(k+1,temp,ans,nums,n);
        temp.pop_back();
        int j=k+1;
        while(j<n&&nums[j]==nums[k]){
            j++;
        }
        helper(j,temp,ans,nums,n);

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