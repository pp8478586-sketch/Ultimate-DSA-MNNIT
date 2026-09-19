class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});
        if(numRows==1)return ans;
        ans.push_back({1,1});
        if(numRows==2)return ans;
        for(int i=2;i<numRows;i++){
            vector<int>temp;
            temp.push_back(1);
            vector<int>prev;
            if(i>1){
                prev=ans[i-1];
            }
            for(int j=0;j<prev.size()-1;j++){
                temp.push_back(prev[j]+prev[j+1]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};