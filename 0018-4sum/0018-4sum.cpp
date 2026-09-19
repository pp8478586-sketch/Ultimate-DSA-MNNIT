class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            while(i<n &&i>0&&nums[i]==nums[i-1]){
                i++;
            }
            for(int j=i+1;j<n;j++){
                if(j>i+1&&nums[j]==nums[j-1]){
                   continue;
                }
                int begin=j+1;
                int end=n-1;
                while(begin<end){
                    long long sum=1LL*nums[i]+1LL*nums[j]+1LL*nums[begin]+1LL*nums[end];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[begin],nums[end]});
                        begin++;
                        while(begin<end&&nums[begin]==nums[begin-1]){
                            begin++;
                        }
                    }
                    else if(sum<target){
                        begin++;
                    }
                    else{
                        end--;
                    }
                }  
            }
        }
        return ans;
    }
};