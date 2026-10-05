class Solution { 
    void helper(int target,int i,int k,vector<int>&nums,vector<int>temp,vector<vector<int>>&ans){
        if(target==0&&k==0){
            ans.push_back(temp);
            return ;
        }
        if(target>0&&k==0){
            return ;
        }
        for(int j=i;j<9;j++){
            if(target<nums[j]){
                break ;
            }
            temp.push_back(nums[j]);
            helper(target-nums[j],j+1,k-1,nums,temp,ans);
            temp.pop_back();
        }

    }
           
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums;
        vector<vector<int>>ans;
        vector<int>temp;
        for(int i=1;i<=9;i++){
            nums.push_back(i);
        }
        helper(n,0,k,nums,temp,ans);
        return ans;

        
    }
};