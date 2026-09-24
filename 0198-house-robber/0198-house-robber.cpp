class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];
        int prev1=nums[0];
        int prev2=nums[1];
        for(int i=2;i<n;i++){
            int newSum=prev1+nums[i];
            prev1=max(prev1,prev2);
            prev2=newSum;
        }
        return max(prev2,prev1);
    }
};