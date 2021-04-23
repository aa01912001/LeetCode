class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if(hand.size() % W != 0) return false;
        if(W == 1) return hand.size() >= W;
        
        map<int, int> occurs;
        for(int i=0; i<hand.size(); i++) { // count the number of each value
            occurs[hand[i]]++;
        }
        
        int group_num = 0;
        int pre = 0;
        for(int i=0; i<hand.size(); i++) {
            if(i%W == 0) { // if the first number of each group
                pre = occurs.begin()->first;
                if(--occurs[pre] == 0) occurs.erase(pre);
                continue;
            }
            
            int next = pre+1;
            if(occurs.find(next) == occurs.end()) return false;
        
            if(--occurs[next] == 0) occurs.erase(next);
            pre = next;
            
            if(i%W == W-1) group_num++; // if the last number of each group
        }
        
        return true;
    }
};