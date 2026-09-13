class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>prefixMax(n,-1);
        vector<int>suffixMax(n,-1);
        int leftMax=0;
         int rightMax=n-1;
        for(int i=0;i<n;i++){
            
            if(height[i]>height[leftMax]){
                prefixMax[i]=i;
                leftMax=i;
            }
            else{
                prefixMax[i]=leftMax;
            }
        }
        for(int i=n-1;i>=0;i--){
           
            if(height[i]>height[rightMax]){
                suffixMax[i]=i;
                rightMax=i;
            }
            else{
                suffixMax[i]=rightMax;
            }
        }
        int water=0;
        for(int i=0;i<n;i++){
            if(height[prefixMax[i]]>height[i]&&height[suffixMax[i]]>height[i]){
                 water+=(min(height[prefixMax[i]],height[suffixMax[i]])-height[i]);
            }
           
        }
        return water;
        
    }
};