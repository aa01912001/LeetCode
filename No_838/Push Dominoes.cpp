class Solution {
public:
    string pushDominoes(string dominoes) {
        int l = -1;
        for(int i=0; i<dominoes.length(); i++) { // consider all chars between any 'R'...'L' patterns
            if(dominoes[i] == 'R') { 
                l = i;
            }
            
            if(dominoes[i] == 'L') {
                int s = l;
                int mid = (l+i)/2;
                if(l != -1) { // if it has previous 'R' on the left 
                    while(l <= mid) {
                        dominoes[l] = 'R';
                        l++;
                    }
                    
                    while(l <= i) {
                        dominoes[l] = 'L';
                        l++;
                    }
                    
                    if((i-s+1)%2 == 1) dominoes[mid] = '$';
                }
                l = -1;
            } 
        }
        
        for(int i=1; i<dominoes.length(); i++) {
            if(dominoes[i] == '.') {
                if(dominoes[i-1] == 'R') {
                    dominoes[i] = 'R';
                }
            }
        }
        
        for(int i=dominoes.length()-2; i>=0; i--) {
            if(dominoes[i] == '.') {
                if(dominoes[i+1] == 'L') {
                    dominoes[i] = 'L';
                }
            }
        }
        
        for(int i=0; i<dominoes.length(); i++) { // change '$' into '.'
            if(dominoes[i] == '$') {
                dominoes[i] = '.';
            }
        }
        
        return dominoes;
    }
};