class Solution {
    void helper(vector<int>temp,vector<int>nums,int n,int k,vector<vector<int>>&ans){
        if(k==n){
            ans.push_back(temp);
            return;
        }
            temp.push_back(nums[k]);
            helper(temp,nums,n,k+1,ans);
            temp.pop_back();
            helper(temp,nums,n,k+1,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n=nums.size();
        helper(temp,nums,n,0,ans);
        return ans;
    }
};