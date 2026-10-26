class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>ans(arr.size(),0);
        if(arr.size()==0)return ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<arr.size();i++){
            pq.push({arr[i],i});
        }
        ans[pq.top().second]=1;
        int prev=pq.top().first;
        pq.pop();
        int curr=1;
        while(!pq.empty()){
            if(pq.top().first==prev){
                ans[pq.top().second]=curr;
            }
            else{
                ans[pq.top().second]=curr+1;
                curr++;
            }
            prev=pq.top().first;
            pq.pop();
        }
        return ans;
        
    }
};