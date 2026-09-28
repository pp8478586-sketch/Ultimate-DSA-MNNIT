class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int>dp(n);
        for(int i=0;i<n;i++){
            vector<int>temp(n,0);
            for(int j=0;j<n;j++){
                if(i==0){
                    dp[j]=matrix[i][j];
                }
                else{
                    int first=INT_MAX;
                    if(j-1>=0)first=dp[j-1];
                    int second=dp[j];
                    int third=INT_MAX;
                    if(j+1<n) third=dp[j+1];
                    int mini=min(first,second);
                    mini=min(mini,third);
                    temp[j]=matrix[i][j]+mini;
                }
            }
            if(i>0)dp=temp;
        }
        return *min_element(dp.begin(),dp.end());


    }
};