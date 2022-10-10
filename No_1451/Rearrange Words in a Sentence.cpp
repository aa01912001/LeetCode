class Solution {
public:
    string arrangeWords(string text) {
        vector<string> sortedSentence;
        istringstream in(text);
        string t;
        while(in >> t) {
            sortedSentence.push_back(t);
        }
        reverse(sortedSentence.begin(), sortedSentence.end());
        stable_sort(sortedSentence.begin(), sortedSentence.end(), [](string i, string j){
            if(i.length() <= j.length())
                return true;
            return false;
        });
        
        string ret = "";
        if(!isupper(sortedSentence[0][0])) 
            sortedSentence[0][0] += 'A' - 'a';
        ret += sortedSentence[0] + " ";
        
        for(int i=1; i<sortedSentence.size()-1; i++) {
            if(isupper(sortedSentence[i][0])) 
                sortedSentence[i][0] += 'a' - 'A';
            ret += sortedSentence[i] + " ";
        }
        
        if(isupper(sortedSentence[sortedSentence.size()-1][0])) 
                sortedSentence[sortedSentence.size()-1][0] += 'a' - 'A';
        ret += sortedSentence.back();
            
        return ret;
    }
};