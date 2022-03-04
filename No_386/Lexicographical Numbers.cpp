class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret;
        DFS(0, n, ret);
        return ret;
    }
    
    void DFS(int num, int& n, vector<int>& ret) {
        for(int i=0; i<=9; i++) {
            if(num == 0 && i == 0) continue;
            num += i;
            if(num <= n) {
                ret.push_back(num);
                DFS(num*10, n, ret);    
            } else {
                break;
            }
            num -= i;
        }
        
        return;
    }
};