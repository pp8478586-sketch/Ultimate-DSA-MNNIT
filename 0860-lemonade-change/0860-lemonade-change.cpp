class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int>arr(5,0);
        for(int i=0;i<bills.size();i++){
            int temp=bills[i]/5;
            arr[temp]++;
            int requirement=bills[i]-5;
            if(requirement==5){
                if(arr[1]==0){
                    return false;
                }
                else{
                    arr[1]--;
                }
            }
            if(requirement==15){
                if(arr[1]>0&&arr[2]>0){
                    arr[2]--;
                    arr[1]--;
                }
                else if(arr[1]>=3){
                    arr[1]-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};