class StockSpanner {
private:
    stack<pair<int, int>> allPrice;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ret = 1;
        while(!allPrice.empty() && price >= allPrice.top().first) {
            ret += allPrice.top().second;
            allPrice.pop();
        }
        
        allPrice.push({price, ret});
        return ret;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */