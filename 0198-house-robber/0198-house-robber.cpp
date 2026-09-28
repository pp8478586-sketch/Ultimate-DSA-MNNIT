class Solution {
public:
    int rob(vector<int>& nums) {
        // this is sapce otpimization appraoch of the tabulation approach 
        int n=nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[1],nums[0]);
        int first=nums[0];
        int second=max(nums[1],nums[0]);
        for(int i=2;i<n;i++){
            int curr=max(first+nums[i],second);
            first=second;
            second=curr;
        }
        return second;
    }
};