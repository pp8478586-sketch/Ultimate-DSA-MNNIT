class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>st;
        int n=height.size();
        int count=0;
        int maxLeftHeight=0;
        stack<int>st2;
        for(int i=0;i<n;i++){
            int compare=min(maxLeftHeight,height[i]);
            while(!st.empty()&&height[st.top()]<compare){
                count+=compare-height[st.top()];
                st2.push(st.top());
                st.pop();
            }
            while(!st2.empty()){
                st.push(st2.top());
                height[st2.top()]=compare;
                st2.pop();
            }
            st.push(i);
            maxLeftHeight=max(maxLeftHeight,height[i]);

        }
        return count;
    }
};