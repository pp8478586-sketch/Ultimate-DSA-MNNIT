class StockSpanner {
    stack<pair<int,int>>st;
public:
    StockSpanner() {
        
    }
    int next(int price) {
        if(st.empty()){
            st.push({price,1});
        }
        else{
            if(st.top().first<=price){
                int count=1;
                while(!st.empty()&&st.top().first<=price){
                    count+=st.top().second;
                    st.pop();
                }
                st.push({price,count});
            }
            else{
                st.push({price,1});
            }
        }
        return st.top().second;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */