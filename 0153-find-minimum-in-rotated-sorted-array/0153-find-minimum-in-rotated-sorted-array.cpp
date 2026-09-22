class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int n=nums.size();
        int high=n-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[high]<nums[mid]){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return nums[low];
    }
};