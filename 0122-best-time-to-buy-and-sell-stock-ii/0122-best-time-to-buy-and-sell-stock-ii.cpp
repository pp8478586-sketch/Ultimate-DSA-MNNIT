class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int buy=prices[0];
        for(int i=0;i<prices.size();i++){
            if(prices[i]>buy){
                maxprofit+=prices[i]-buy;
                buy=prices[i];
            }
            else{
                buy=prices[i];
            }
        }
        return maxprofit;
        
    }
};