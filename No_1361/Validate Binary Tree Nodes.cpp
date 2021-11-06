class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> degree(n, 0), set(n, -1);
        for(int i=0; i<n; i++) {
            int left = leftChild[i];
            int right = rightChild[i];
            int a = FindSet(set, i);
            
            if(left != -1) {
                degree[left]++;
                int b = FindSet(set, left);
                if(a != b) {
                    set[left] = i;
                }
            }
            
            if(right != -1) {
                degree[right]++;
                int c = FindSet(set, right);
                if(a != c) {
                    set[right] = i;
                }
            }
        }
        
        int zeroDegree = 0;
        int posOfZeroDegree;
        for(int i=0; i<n; i++) {
            if(degree[i] > 1) return false; // if tree has loop
            if(degree[i] == 0) {
                zeroDegree++;
                posOfZeroDegree = i;
            }
        }
        
        int component = 0;
        for(int i=0; i<set.size(); i++) {
            if(set[i] == -1) component++;
        }
        
        if(component != 1) return false;
        
        return zeroDegree == 1;
    }
    
    int FindSet(vector<int>& set, int num) {
        int t = num;
        while(set[t] != -1) {
            t = set[t];
        }
        return t;
    }
};