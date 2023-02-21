class Solution {
public:
    int minimumBuckets(string hamsters) {
        int ret = 0;
        hamsters = "@" +  hamsters + "@";
        
        for(int i=1; i<hamsters.size()-1; i++) {
            if(hamsters[i] == 'H') {
                if(hamsters[i+1] == '.') {
                    ret++;
                    i+=2;
                } else if(hamsters[i-1] == '.') {
                    ret++;
                } else {
                    return -1;
                }
            }
        }
        
        return ret;
    }
};