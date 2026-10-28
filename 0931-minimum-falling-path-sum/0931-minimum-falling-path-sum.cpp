class Solution {
   
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>prev(m,0);
        for(int i=0;i<n;i++){
            vector<int>curr(m,0);
            for(int j=0;j<m;j++){
                if(i==0){
                    curr[j]=matrix[i][j];
                    continue;
                }
                else{
                    int up=prev[j];
                    int left=1e9;
                    int right=1e9;
    
                    if(j-1>=0)left=prev[j-1];
                    if(j+1<m)right=prev[j+1];
                    curr[j]=matrix[i][j]+min({left,up,right});
                }
            }
            prev=curr;
        }
        return *min_element(prev.begin(),prev.end());
       
    }
};