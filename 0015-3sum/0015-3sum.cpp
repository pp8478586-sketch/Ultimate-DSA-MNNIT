class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(i<n&&i>0&&nums[i]==nums[i-1]){
                i++;
            }
            int end =n-1;
            int j=i+1;
            while(j<end){
                int sum=nums[i]+nums[j]+nums[end];
                if(sum==0){
                    ans.push_back({nums[i],nums[j],nums[end]});
                    j++;
                    while(j<end&nums[j]==nums[j-1]){
                        j++;
                    }
                }
                else if(sum<0){
                    j++;
                }
                else{
                    end--;
                }
            }
        }
        return ans;
        
    }
};