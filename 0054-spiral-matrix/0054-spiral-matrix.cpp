class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int>ans;
        int m=matrix[0].size();
        int ur=0;
        int br=n-1;
        int lc=0;
        int rc=m-1;
        while(ur<=br&&lc<=rc){
            for(int i=lc;i<=rc;i++){
                ans.push_back(matrix[ur][i]);
            }
            for(int i=ur+1;i<=br;i++){
                ans.push_back(matrix[i][rc]);
            }
            if(ur<br){
                for(int i=rc-1;i>=lc;i--){
                    ans.push_back(matrix[br][i]);
                }
            }
            if(lc<rc){
                for(int i=br-1;i>=ur+1;i--){
                    ans.push_back(matrix[i][lc]);
                }
            }
            
            ur++;
            br--;
            lc++;
            rc--;
        }
        return ans;
    }
};