class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int minEl=prices[0];
        for(int i=0;i<prices.size();i++){
            int profit=prices[i]-minEl;
            maxProfit=max(profit,maxProfit);
            minEl=min(minEl,prices[i]);
        }
        return maxProfit;
        
    }
};