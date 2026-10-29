class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<vector<int>>bucket(nums.size()+1);
        for(int x:nums){
            mp[x]++;
        }
        for(auto it:mp){
            bucket[it.second].push_back(it.first);
        }
        vector<int>ans;
        for(int f=nums.size();f>=1 &&k>ans.size();f--){
            for(int x:bucket[f]){
                ans.push_back(x);
                if(ans.size()==k){
                    break;
                }
            }
        }
        return ans;
    }
};