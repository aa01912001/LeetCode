class Solution {
public:
    string shortestPalindrome(string s) {
        string r = s; 
        reverse(r.begin(), r.end());
        
        string t = s + "@" + r;
        cout << t << endl;
        vector<int> next(t.length(), 0);
        for (int i=1; i<t.length(); i++) {
            int j = next[i-1];
            while (j > 0 && t[i] != t[j]) {
                j = next[j-1];
            }
            next[i] = j + (t[i] == t[j]);
        }

        return r.substr(0, r.length()-next.back()) + s;
    }
};