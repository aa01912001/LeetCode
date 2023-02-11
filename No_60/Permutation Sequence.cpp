class Solution {
public:
    string getPermutation(int n, int k) {
        set<char> treeSet{1, 2, 3, 4, 5, 6, 7, 8, 9};
        string ret = "";
        
        long long factorial = 1;
        for(int i=1; i<=n; i++) 
            factorial *= i;

        for(int i=n; i>=2 ; i--) {
            // to get each char left to right
            factorial /= i;
            for(int j=1; j<=i; j++) {
                // to find a (j-1)th smallest element in remaining chars
                // and put it into current position
                if(factorial * j >= k) {
                    k -= factorial * (j - 1);
                    int count = 0;
                    for(int num : treeSet) {
                        // to get (j-1)th smallest element in tree set
                        if(count == j-1) {
                            ret += to_string(num);
                            treeSet.erase(num);
                            break;
                        }
                        count++;
                    }
                    break;
                }
            }
        }

        ret += to_string(*treeSet.begin());

        return ret;
    }
};