class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        stack<int>st;
        for(int i=0;i<=n;i++){
            while(!st.empty()&&(i==n||nums[st.top()]>=nums[i])){
                int mid=st.top();
                st.pop();
                int left=st.empty()?-1:st.top();
                int right=i;
                ans=ans-1LL*nums[mid]*(mid-left)*(right-mid);
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=0;i<=n;i++){
            while(!st.empty()&&(i==n||nums[st.top()]<=nums[i])){
                int mid=st.top();
                st.pop();
                int right=i;
                int left=st.empty()?-1:st.top();
                ans=ans+1LL*nums[mid]*(mid-left)*(right-mid);
            }
            st.push(i);
        }
        return ans;
    }
};