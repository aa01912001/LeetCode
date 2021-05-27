class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> hset;
        for(int i=0; i<dictionary.size(); i++) {
            hset.insert(dictionary[i]);
        }
        
        vector<string> t;
        string word = "";
        for (auto x : sentence) { // split sentence
            if (x == ' ') {
                t.push_back(word);
                word = "";
            } else {
                word = word + x;
            }
        }
        t.push_back(word);
        
        string ret = "";
        for(int i=0; i<t.size(); i++) { // replace every single word
            string tmp = t[i];
            int len = t[i].length();
            int j = 0;
            while(j != len) { // compare to dictionary from shortest to longest substring
                if(hset.find(t[i].substr(0, j+1)) != hset.end()) {
                    tmp = t[i].substr(0, j+1);
                    break;
                }
                j++;
            }
            
            ret += tmp;
            ret += " ";
        }
        return ret.substr(0, ret.length()-1);
    }
};