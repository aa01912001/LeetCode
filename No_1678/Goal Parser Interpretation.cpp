class Solution {
public:
    string interpret(string command) {
        string  s = "";
        int left;
        for(int i=0; i<command.length(); i++) {
            if(command[i] == 'G') {
                s += "G";
            }else if(command[i] == '(') {
                left = i;
            }else if(command[i] == ')') {
                if(i - left == 1) {
                    s += "o";
                }else {
                    s += "al";
                }
            }
        }
        
        return s;
    }
};