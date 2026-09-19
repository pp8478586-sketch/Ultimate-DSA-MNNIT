class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        int n=nums.size();
        int i=0;
        while(i<n){
            int current=nums[i];
            int count=0;
            while(i<n&&current==nums[i]){
                count++;
                i++;
            }
            if(count>n/3){
                ans.push_back(current);
            }
        }
        return ans;
    }
};