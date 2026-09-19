class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=0;i<numRows;i++){
            vector<int>temp;
            temp.push_back(1);
            for(int r=1;r<=i;r++){
                if(r>i/2){
                    temp.push_back(temp[i-r]);
                }
                else{
                    temp.push_back((temp[r-1]*(i-r+1))/r);
                }
                
            }
            ans.push_back(temp);
        }
        return ans;
    }
};