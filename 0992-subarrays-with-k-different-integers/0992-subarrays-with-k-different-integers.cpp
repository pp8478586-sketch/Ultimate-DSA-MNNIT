class Solution {
    int helper(vector<int>&nums,int k){
        unordered_map<int,int>mp;
        int begin=0;
        int total=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            while(mp.size()>k){
                mp[nums[begin]]--;
                if(mp[nums[begin]]==0){
                    mp.erase(nums[begin]);
                }
                begin++;
            }
            total+=i-begin+1;
        }
        return total;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return helper(nums,k)-helper(nums,k-1);
    }
};