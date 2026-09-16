class Solution {
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n=heights.size();
        long long maxArea=0;
        for(int i=0;i<=n;i++){
            while(!st.empty()&&(i==n||heights[st.top()]>=heights[i])){
                int mid=st.top();
                st.pop();
                int left=st.empty()?-1:st.top();
                int right=i;
                int height=heights[mid];
                int width=right-left-1;
                long long  area =1LL*height*width;
                maxArea=max(maxArea,area);
            }
            st.push(i);
        }
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        long long maxArea=0;
        vector<int>heights(m,0);
        for(int i=0;i<n;i++ ){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0'){
                    heights[j]=0;
                }
                else{
                    heights[j]=heights[j]+1;
                }
            }
            long long area=largestRectangleArea(heights);
            maxArea=max(maxArea,area);
            
        }
        return maxArea;
        
    }
};