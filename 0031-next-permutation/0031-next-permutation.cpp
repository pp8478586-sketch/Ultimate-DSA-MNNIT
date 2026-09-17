class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();  
        int k=n-2;
        int prev=nums[n-1];
        while(k>=0&&nums[k]>=prev){
            prev=nums[k];
            k--;
        }
        if(k==-1){
            return reverse(nums.begin(),nums.end());
        }
        int swapEl=k+1;
        for(int i=k+1;i<n;i++){
            if(nums[k]<nums[i]){
                if(nums[swapEl]>nums[i]){
                    swapEl=i;
                }
            }
        }
        swap(nums[k],nums[swapEl]);
        sort(nums.begin()+k+1,nums.end());
        

    }
};