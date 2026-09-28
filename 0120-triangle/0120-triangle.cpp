class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int>dp;
        for(int i=0;i<n;i++){
            int k=triangle[i].size();
            vector<int>temp(k,0);
            for(int j=0;j<k;j++){
                if(i==0){
                    dp.push_back(triangle[i][j]);
                }
                else{
                    int first=INT_MAX;
                    if(j-1>=0){
                         first=dp[j-1];
                    }
                    int second=INT_MAX;
                    if(j<k-1)second=dp[j];
                    int mini=min(first,second);
                    temp[j]=mini+triangle[i][j];

                }
            }
            if(i>0)dp=temp;
        }
        return *min_element(dp.begin(),dp.end());
    }

};