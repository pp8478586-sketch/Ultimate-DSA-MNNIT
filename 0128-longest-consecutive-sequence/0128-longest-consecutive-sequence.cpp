class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n =nums.size();
        for(int i=0 ;i<n ;i++){
            mp[nums[i]]=1;
        }
        int maxCount=0;
        for(auto it:mp){
        int j=it.first;
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