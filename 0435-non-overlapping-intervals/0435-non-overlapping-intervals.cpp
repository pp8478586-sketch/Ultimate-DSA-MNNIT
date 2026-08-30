class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=0;
        int n=intervals.size();
        vector<vector<int>>sorted;
        for(int i=0;i<n;i++){
        sorted.push_back({intervals[i][1],intervals[i][0]});
        }
        sort(sorted.begin(), sorted.end());
        int last=INT_MIN;
        for(int i=0;i<n;i++){
            if(sorted[i][1]<last){
                ans++;
            }
            else{
                last=sorted[i][0];
            }
            
        }
        return ans;
    }
};