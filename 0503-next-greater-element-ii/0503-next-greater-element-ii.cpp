class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
       
        stack<int>st;
        int n=nums.size();
        vector<int>ans(n,-1);
        for(int i=0;i<2*n;i++){
            int k=i%n;
            while(!st.empty()&&nums[st.top()]<nums[k]){
                ans[st.top()]=nums[k];
                st.pop();
            }
            if(i<n)st.push(k);
        }
       
        return ans;
    }
};