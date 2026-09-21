class Solution {
    void merge(vector<int>&nums,int low,int mid,int high){
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
    }
    void helper(vector<int>&nums,int &pairs,int low,int high){
        if(low>=high)return;
        int mid=(low+high)/2;
        helper(nums,pairs,low,mid);
        helper(nums,pairs,mid+1,high);
        int second=low;
        for(int i=mid+1;i<=high;i++){
            while(second<=mid&&nums[second]<=2LL*nums[i]){
                second++;
            }
            pairs+=mid-second+1;
        }
        merge(nums,low,mid,high);
    }

public:
    int reversePairs(vector<int>& nums) {
        int pairs=0;
        int n=nums.size();
        if(n<=1)return 0;
        helper(nums,pairs,0,n-1);
        return pairs;
    }
};