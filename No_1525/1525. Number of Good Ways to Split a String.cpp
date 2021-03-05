class Solution {
public:
    int numSplits(string s) {
        int rCount[26];
        int lCount[26];
        memset(rCount, 0, sizeof(rCount));
        memset(lCount, 0, sizeof(lCount));
        int ret =0;
        
        for(int i=0; i<s.length(); i++) { // count the number of distinct letters in s
            rCount[s[i]-'a']++;
        }
        
        for(int i=0; i<s.length(); i++) { // split s into two strings
            lCount[s[i]-'a']++;
            rCount[s[i]-'a']--;
            if(compare(lCount, rCount)) ret++;
        }
        return ret;
    }
    
    bool compare(int A[], int B[]) { // compare the number of distinct letters of two splits
        int aCount = 0, bCount = 0;
        for(int i=0; i<26; i++) {
            if(A[i] > 0) aCount++;
            if(B[i] > 0) bCount++;
        }
        return aCount == bCount;
    }
};