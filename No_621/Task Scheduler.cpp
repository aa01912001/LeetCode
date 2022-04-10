class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26);
        priority_queue<int> q;
        int size = tasks.size();
        
        for(int i=0; i<size; i++) { // count the frequency of each type
            count[tasks[i]-'A']++;
        }
        
        for(int i=0; i<26; i++) { // push the frequencis into max heap
            if(count[i] > 0) {
                q.push(count[i]);
            }
        }
        
        int ret = 0;
        int finished = 0; // # of finished tasks
        while(finished != size) {
            int r = q.size(); // # of remaining unfinished types
            if(r >= n+1) { // do not need to insert any idle
                finishTasks(q, n+1);
                finished += n + 1;
            } else { // need to insert idle
                finishTasks(q, r);
                finished += r;
                if(finished != size) ret += n + 1 - r;
            }
        }
        
        return ret + size;
    }
    
    void finishTasks(priority_queue<int>& q, int num) { // to finish some tasks
        stack<int> s;
        while(num != 0) { // pick top num much types to be finished
            int t = q.top()-1; q.pop();
            if(t != 0) {
                s.push(t);
            }
            num--;
        }
        while(!s.empty()) {
            q.push(s.top()); s.pop();
        }
        return;
    } 
};