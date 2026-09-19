class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>st;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            int end =n-1;
            int j=i+1;
            while(j<end){
                int diff=-nums[i]-nums[j];
                if(diff==nums[end]){
                    st.insert({nums[i],nums[j],nums[end]});
                }
                if(diff<nums[end]){
                    end--;
                }
                else{
                    j++;
                }
            }
           
        }
         for(auto x: st){
                ans.push_back(x);
            }
            return ans;
    }
};