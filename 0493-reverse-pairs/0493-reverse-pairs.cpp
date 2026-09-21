class Solution {
    
    int  merge(vector<int>&nums,int low,int high){
        if(low>=high)return 0;
        int mid=low+(high-low)/2;
        long long count=0;
        count+=merge(nums,low,mid);
        count+=merge(nums,mid+1,high);
        // count all the pairs between the two sorted halves
        int pointer=mid+1;
        for(int i=low;i<=mid;i++){
            while(pointer<=high&&2LL*nums[pointer]<nums[i]){
                pointer++;
            }
            count+=pointer-(mid+1);
        }
        int first=low;
        int second=mid+1;
        vector<int>temp;
        while(first<=mid&&second<=high){
            if(nums[first]<=nums[second]){
                temp.push_back(nums[first]);
                first++;
            }
            else if(nums[first]>nums[second]){
                temp.push_back(nums[second]);
                second++;
            }
        }
        while(first<=mid){
            temp.push_back(nums[first]);
            first++;
        }
        while(second<=high){
            temp.push_back(nums[second]);
            second++;
        }
        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
        return count;
    }
public:
    int reversePairs(vector<int>& nums) {
        return merge(nums,0,nums.size()-1);
        
    }
};