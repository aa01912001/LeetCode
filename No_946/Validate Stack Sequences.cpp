class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int index = 0;
        stack<int> s;
        for(int i=0; i<popped.size(); i++) {
            
            if(index == pushed.size() && s.top() != popped[i]) { // if deadlock
                return false;
            }
            
            if(!s.empty() && s.top() == popped[i]) { // if top of stack equals to popped[i]
                s.pop();
                continue;
            }
            
            while(index < pushed.size()) { // push pushed[index] into stack until pushed[index] == poped[i]
                if(pushed[index] != popped[i]) {
                    s.push(pushed[index]);
                    index++;
                }else {
                    index++;
                    break;
                }
            }
            
        }
        
        return true;
    }
};