class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int first=nums[0];
        if(n==1)return first;
        int second=max(nums[1],nums[0]);
        if(n==2)return second;
        for(int i=2;i<n-1;i++){
            int curr=max(nums[i]+first,second);
            first=second;
            second=curr;
        }
        int ans1=second;
        first=nums[1];
        second=max(nums[2],nums[1]);
        for(int i=3;i<n;i++){
            int curr=max(nums[i]+first,second);
            first=second;
            second=curr;
        }
        int ans2=second;
        return max(ans1,ans2);
        
        
    }
};