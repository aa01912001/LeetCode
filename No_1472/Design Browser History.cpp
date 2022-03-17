class BrowserHistory {
private:
    string cur;
    stack<string> fwd, bck;
public:
    BrowserHistory(string homepage) {
        cur = homepage;
    }
    
    void visit(string url) {
        while(!fwd.empty()) fwd.pop();
        bck.push(cur);
        cur = url;
    }
    
    string back(int steps) {
        while(!bck.empty() && steps--) {
            fwd.push(cur);
            cur = bck.top(); bck.pop();
        }
        return cur;
    }
    
    string forward(int steps) {
        while(!fwd.empty() && steps--) {
            bck.push(cur);
            cur = fwd.top(); fwd.pop();
        }
        return cur;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */