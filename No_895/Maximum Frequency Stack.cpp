class FreqStack {
private:
    int maxFreq;
    unordered_map<int, int> frequency; // num : frequency
    unordered_map<int, stack<int>> frequencyStack; // frequency : stack of nums with this frequency
public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        frequency[val]++;
        maxFreq = max(maxFreq, frequency[val]);
        frequencyStack[frequency[val]].push(val);
        return;
    }
    
    int pop() {
        int ret = frequencyStack[maxFreq].top();
        frequencyStack[maxFreq].pop();
        if(frequencyStack[maxFreq].empty()) {
            maxFreq--;
        }
        frequency[ret]--;
        
        return ret;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */