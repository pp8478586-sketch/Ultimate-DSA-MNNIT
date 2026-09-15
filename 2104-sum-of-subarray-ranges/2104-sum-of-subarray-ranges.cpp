class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int>prevSmaller(n,-1);
        vector<int>nextSmaller(n,n);
        vector<int>prevGreater(n,-1);
        vector<int>nextGreater(n,n);
        stack<int>st;
        long long minSum=0;
        long long maxSum=0;
        for(int i=0;i<n;i++){
            while(!st.empty()&&nums[st.top()]>=nums[i]){
                nextSmaller[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[st.top()]>nums[i]){
                prevSmaller[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=0;i<n;i++){
            minSum=minSum+1LL*nums[i]*(i-prevSmaller[i])*(nextSmaller[i]-i);
        }
        for(int i=0;i<n;i++){
            while(!st.empty()&&nums[st.top()]<=nums[i]){
                nextGreater[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[st.top()]<nums[i]){
                prevGreater[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        for(int i=0;i<n;i++){
            maxSum=maxSum+1LL*nums[i]*(i-prevGreater[i])*(nextGreater[i]-i);
        }
        return maxSum-minSum;

    }
};