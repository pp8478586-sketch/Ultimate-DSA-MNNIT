class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left=0;
        long long  sum=0;
        int n=nums.size(); 
        int maxFreq=INT_MIN; 
        for(int right=0;right<n;right++){
            sum+=nums[right];
            while(1LL*(right-left+1)*nums[right]-sum>k){
                sum-=nums[left];
                left++;
            }
            maxFreq=max(maxFreq,right-left+1); 
        }
        return maxFreq;
    }
};