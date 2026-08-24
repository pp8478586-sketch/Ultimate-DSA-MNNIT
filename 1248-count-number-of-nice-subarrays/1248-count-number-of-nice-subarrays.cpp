class Solution {
    int helper(vector<int>&nums,int k){
        int begin=0;
        int cnt=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==1){
                cnt++;
            }
            while(cnt>k){
                if(nums[begin]%2==1){
                    cnt--;
                }
                begin++;
            }
            ans+=i-begin+1;
        }
        return ans;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};