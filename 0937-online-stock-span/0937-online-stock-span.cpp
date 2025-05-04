class StockSpanner {
    private:
    stack<pair<int, int>> st; // pair: {price, span}
    
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
         int span = 1;
        // While the top of stack has price <= current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */