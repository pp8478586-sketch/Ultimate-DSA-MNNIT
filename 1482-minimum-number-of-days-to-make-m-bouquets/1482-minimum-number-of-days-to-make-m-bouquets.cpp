class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(1LL*m*k>bloomDay.size())return -1;
        int low=1;
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            int bouquets=0;
            int count=0;
            for(int i=0;i<bloomDay.size();i++){
                if(bloomDay[i]<=mid){
                    count++;
                }
                else{
                    count=0;
                }
                if(count==k){
                    bouquets++;
                    count=0;
                }
            }
            if(bouquets<m){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};