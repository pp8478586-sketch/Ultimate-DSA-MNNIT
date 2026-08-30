class Solution {
    vector<int>insert(vector<int>a,vector<int>b){
        return {min(a[0],b[0]),max(a[1],b[1])};
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>>ans;
       
        int n=intervals.size();
        for(int i=0;i<n;i++){
            // if newinterval is after the  current interval and no overlap 
            if(newInterval[0]>intervals[i][1]){
                ans.push_back(intervals[i]);
            }
            // if newInterval is under this current interval or overlap 
            else if(newInterval[0]<=intervals[i][1]&&newInterval[1]>=intervals[i][0]){
                newInterval=insert(newInterval,intervals[i]);
            }
            // after the overlap region
            else{
                ans.push_back(newInterval);
                newInterval=intervals[i];
            }
        }
        ans.push_back(newInterval);
        return ans;
    }
};