class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high=*max_element(piles.begin(),piles.end());
        int low=1;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long  sum=0;
            for(int i=0;i<piles.size();i++){
                int ans=(piles[i]+mid-1)/mid;
                sum=sum+ans;
            }
            if(sum<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};