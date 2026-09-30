class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int low=0;
        int high=m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int colInd=0;
            int maxEl=mat[mid][colInd];
            for(int i=0;i<n;i++){
                if(mat[mid][i]>maxEl){
                    colInd=i;
                    maxEl=mat[mid][colInd];
                }
            }
            int uEl=(mid-1>=0)?mat[mid-1][colInd]:-1;
            int lEl=(mid+1<m)?mat[mid+1][colInd]:-1;
            if(maxEl>uEl&&maxEl>lEl){
                return {mid,colInd};
            }
            else if(maxEl<uEl){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return {0,0};
    }
};