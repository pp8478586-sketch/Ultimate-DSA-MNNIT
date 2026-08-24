class Solution {
    int atMost(vector<int>&nums,int goal){
        if(goal<0)return 0;
        int sum=0;
        int count=0;
        int begin=0;
        int leadingZero=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(sum>goal){
                sum-=nums[begin];
                begin++;
            }
            count+=i-begin+1;
        }
        return count;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums,goal)-atMost(nums,goal-1);
    }
};