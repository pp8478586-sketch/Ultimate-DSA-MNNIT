class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int>buy(k,INT_MIN);
        vector<int>sell(k,0);
        for(int i=0;i<prices.size();i++){
            int j=1;
            buy[0]=max(buy[0],-prices[i]);
            sell[0]=max(sell[0],buy[0]+prices[i]);
            
            while(j<k){
                buy[j]=max(buy[j],sell[j-1]-prices[i]);
                sell[j]=max(sell[j],buy[j]+prices[i]);
                
                j++;
            }
        }
        return sell[k-1];
        
    }
};