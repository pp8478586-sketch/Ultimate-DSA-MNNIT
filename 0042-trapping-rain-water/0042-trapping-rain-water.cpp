class Solution {
public:
    int trap(vector<int>& height) {
       int water=0;
       stack<int>st;
        for(int i=0;i<height.size();i++){
            while(!st.empty()&&height[st.top()]<height[i]){
                int currHeight=height[st.top()];
                st.pop();
                int left=-1;
                if(!st.empty()){
                    left=st.top();
                }
                if(left!=-1){
                    water+=(i-left-1)*(min(height[left],height[i])-currHeight);
                }
            }
            st.push(i);
        }
        return water;
        
    }
};