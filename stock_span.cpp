class StockSpanner {
public:
    stack<pair<int, int>> s; // pair<price, span>

    StockSpanner() {
    }
    
    int next(int price) {
        int span = 1;
        // While the current price is greater than or equal to the price on top of the stack
        while (!s.empty() && s.top().first <= price) {
            span += s.top().second;
            s.pop();
        }
        s.push({price, span});
        return span;
    }
};
