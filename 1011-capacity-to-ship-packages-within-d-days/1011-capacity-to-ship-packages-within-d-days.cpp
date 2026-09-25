class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int high=0;
        for(int i=0;i<weights.size();i++){
            high+=weights[i];
        }
        int low=*max_element(weights.begin(),weights.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            int noOfDays=1;
            int sum=0;
            int i=0;
                while(i<weights.size()){
                    sum+=weights[i];
                    if(sum>mid){
                        sum=weights[i];
                        noOfDays++;
                    }
                    i++;
                }
            if(noOfDays<=days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            
        }
        return low;
    }
};