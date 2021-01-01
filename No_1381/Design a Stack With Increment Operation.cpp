class CustomStack {
private:
    int *s;
    int top;
    int max_size;
public:
    CustomStack(int maxSize) {
        s = new int[maxSize];
        top = -1;
        max_size = maxSize;
    }
    
    void push(int x) {
        if(top == max_size-1) return;
        s[++top] = x;
        return;
    }
    
    int pop() {
        if(top == -1) return -1;
        top--;
        return s[top+1];
    }
    
    void increment(int k, int val) {
        for(int i=0; i<=top && k; i++, k--) {
            s[i] += val;
        }
        return;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */