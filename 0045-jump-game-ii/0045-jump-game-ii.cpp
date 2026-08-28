class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1)return 0;
        int count=0;
        int currMax=0;
        int farthest=nums[0];
        for(int i=0;i<nums.size();i++){
            if(farthest>=nums.size()-1)return count+1;
            while(i<=farthest){
                currMax=max(currMax,i+nums[i]);
                i++;
            }
            farthest=currMax;
            count++;
            i--;
            currMax=0;
        }
        return count;
    }
};