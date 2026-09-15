class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        stack<int>st;
        long long mod=1e9+7;
        long long  ans=0;
        for(int i=0;i<=n;i++){
            while(!st.empty()&&(i==n||arr[st.top()]>=arr[i])){
                int mid=st.top();
                st.pop();
                int right=i;
                int left=st.empty()? -1:st.top();
                ans=ans+1LL*arr[mid]*(mid-left)*(i-mid);
            }
            st.push(i);
        }
        return ans%mod;

    }
};