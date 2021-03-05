class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, vector<pair<int, int>>> pos; // store the position of 0 ~ 9
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                char c = board[i][j];
                if(c > '9' || c < '1') {
                    continue;
                } else if(pos.find(c) == pos.end()) { // if meet c firstly
                    vector<pair<int, int>> vec;
                    vec.push_back(make_pair(i, j));
                    pos[c] = vec;
                } else { // determine rules
                    for(int index=0; index<pos[c].size(); index++) {
                        int x = pos[c][index].first;
                        int y = pos[c][index].second;
                        if(x == i || y == j) { // match column or row
                            return false;
                        } else {
                            if(i/3 == x/3 && j/3 == y/3) {
                                return false;
                            }
                        }
                    }
                    pos[c].push_back(make_pair(i, j));
                }
            }
        }
        
        return true;
    }
};