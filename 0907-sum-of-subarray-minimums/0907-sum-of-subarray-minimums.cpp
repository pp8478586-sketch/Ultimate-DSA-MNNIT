class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>prevSmaller(n,-1);
        vector<int>nextSmaller(n,n);
        stack<int>st1;
        long long mod=1e9+7;
        long long  ans=0;
        for(int i=0;i<n;i++){
            while(!st1.empty()&&arr[st1.top()]>=arr[i]){
                nextSmaller[st1.top()]=i;
                st1.pop();
            }
            st1.push(i);
        }
        while(!st1.empty()){
            st1.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st1.empty()&&arr[st1.top()]>arr[i]){
                prevSmaller[st1.top()]=i;
                st1.pop();
            }
            st1.push(i);
        }
        for(int i=0;i<n;i++){
            long long  noOfSubArrays=1LL*(i-prevSmaller[i])*(nextSmaller[i]-i);
            ans=(ans+1LL*arr[i]*noOfSubArrays)%mod;
        }
        return ans;



        
    }
};