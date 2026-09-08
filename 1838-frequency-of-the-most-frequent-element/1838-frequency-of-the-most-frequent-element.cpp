class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.rbegin(),nums.rend());
        int count=0;
        int j=0;
        int maxFreq=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(j<n){
                count=count+nums[i]-nums[j];
                if(count>k){
                    count-=nums[i]-nums[j];
                    break;
                }
                j++;
            }
            maxFreq=max(j-i,maxFreq);
            if(i<n-1)count-=(j-i-1)*(nums[i]-nums[i+1]);
        }
        return maxFreq;
        
       
    }
};