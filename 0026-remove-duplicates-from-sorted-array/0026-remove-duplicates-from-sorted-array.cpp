class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int k=1;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                k++;
            }
            nums[k-1]=nums[i];
        }
        return k;
    }
};