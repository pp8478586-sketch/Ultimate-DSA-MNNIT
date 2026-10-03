class Solution {
    void helper(int sum,int target,int i,vector<int>temp,vector<vector<int>>&ans,vector<int>& candidates,int n){
    
        if(sum==target){
            ans.push_back(temp);
            return ;
        }
        if(sum>target||i==n){
            return ;
        }
        if(sum<target){
            temp.push_back(candidates[i]);
            helper(sum+candidates[i],target,i,temp,ans,candidates,n);
            temp.pop_back();
            helper(sum,target,i+1,temp,ans,candidates,n);
        }
       
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n=candidates.size();
        helper(0,target,0,temp,ans,candidates,n);
        return ans;
        
    }
};