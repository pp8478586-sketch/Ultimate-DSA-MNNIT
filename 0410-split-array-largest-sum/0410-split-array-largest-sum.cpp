class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=0;
        for(int i=0;i<nums.size();i++){
            high+=nums[i];
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            int count=1;
            int sum=0;
            for(int num:nums){
                sum+=num;
                if(sum>mid){
                    sum=num;
                    count++;
                }
            }
            if(count>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            
        }
        return low;

    }
};