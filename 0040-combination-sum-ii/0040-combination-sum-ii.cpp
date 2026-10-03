
class Solution {
   void helper(int i,int target,vector<int>temp,vector<vector<int>>&st,vector<int>&candidates){
        if(target==0){
            st.push_back(temp);
            return ;
        }
        if(i>=candidates.size())return ;
        for(int j=i;j<candidates.size();j++){
            if(candidates[j]>target){
                break;
            }
            if(j>i&&candidates[j]==candidates[j-1]){
                continue;
            }
            temp.push_back(candidates[j]);
            helper(j+1,target-candidates[j],temp,st,candidates);
            temp.pop_back();
        }

   }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>st;
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        int n=candidates.size();
        helper(0,target,temp,st,candidates);
        return st;
    }
};