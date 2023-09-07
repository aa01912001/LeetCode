class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> count1, count2;
        
        for (char c : ransomNote) 
            count1[c]++;
        
        for (char c : magazine) 
            count2[c]++;
        
        for (auto p : count1) {
            if (count2[p.first] < p.second)
                return false;
        }
        
        return true;
    }
};