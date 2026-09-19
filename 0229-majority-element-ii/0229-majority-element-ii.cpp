class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        int count=1;
        int n=nums.size();
        int el=nums[0];
        if(n==1)return nums;
        for(int i=1;i<n;i++){
            while(i<n&&nums[i]==el){
                count++;
                i++;
            }
            if(count>n/3){
                ans.push_back(el);
            }
            if(i<n){
                el=nums[i];
                count=1;
                if(count>n/3){
                    ans.push_back(el);
                }
            }            
            
        }
        return ans;
    }
};