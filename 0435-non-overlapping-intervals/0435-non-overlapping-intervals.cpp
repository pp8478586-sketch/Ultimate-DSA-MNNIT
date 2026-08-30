class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=0;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[](const vector<int>&a,const vector<int>&b){
            return a[1]<b[1];
        });
        int last=INT_MIN;
        for(int i=0;i<n;i++){
            if(intervals[i][0]<last){
                ans++;
            }
            else{
                last=intervals[i][1];
            }
        }
        return ans;
    }
};