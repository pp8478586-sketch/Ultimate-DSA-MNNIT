class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int length=0;
        int maxLength=0;
        int count=0;
        int begin=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count++;
            }
            
            while(count>k){
                if(nums[begin]==0){
                    count--;
                }
                begin++;
            }
            
            length=i-begin+1;
            maxLength=max(length,maxLength);
        }
        return maxLength;
    }
};