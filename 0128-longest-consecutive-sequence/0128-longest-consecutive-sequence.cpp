class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>mp;
        int n =nums.size();
        for(int i=0 ;i<n ;i++){
            mp.insert(nums[i]);
        }
        int maxCount=0;
        for(auto it:mp){
        int j=it;
        if(mp.find(j-1)==mp.end()){

            int count=0;
             while(mp.find(j)!=mp.end()){
                j++;
                count++;
            }
            maxCount=max(count,maxCount);
        }

        }
        return maxCount;
    }
};