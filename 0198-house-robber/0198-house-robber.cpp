class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        int first=nums[0];
        int second=nums[1];
        int third=nums[2]+nums[0];
        int maxSum=max(first,second);
            maxSum=max(maxSum,third);
            
        for(int i=3;i<n;i++){
            if(nums[i]>=0){
                int sum1=first+nums[i];
                int sum2=second+nums[i];
                int maxi=max(sum1,sum2);
                maxSum=max(maxSum,maxi);
                first=second;
                second=third;
                third=maxi;
            }
            
            
        }
        return maxSum;
    }
};