class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ret = 0;
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(board[i][j] == '.') continue;
                if(i-1 == -1 && j-1 == -1) {
                    ret++;
                    continue;
                } else if(i == 0 && board[i][j-1] == 'X') {
                    continue;
                } else if(j == 0 && board[i-1][j] == 'X') {
                    continue;
                } else if(i != 0 && j != 0 && (board[i-1][j] == 'X' || board[i][j-1] == 'X')){
                    continue;
                } else {
                    ret++;
                }
            }
        }
        
        return ret;
    }
};