class Solution {
    void helper(int i,int target,vector<int>temp,vector<vector<int>>&ans,vector<int>& candidates,int n){
        if(target==0){
            ans.push_back(temp);
            return ;
        }
        for(int j=i;j<n;j++){
            if(candidates[j]>target){
                break;
            }
            temp.push_back(candidates[j]);
            helper(j,target-candidates[j],temp,ans,candidates,n);
            temp.pop_back();
        }
       
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        int n=candidates.size();
        helper(0,target,temp,ans,candidates,n);
        return ans;
        
    }
};