class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<bool>> board(n, vector<bool>(n));
        
        int ret = 0;
        for(int i=0; i<n; i++) {
            board[0][i] = true;
            ret += backtracking(board, 0, i);
            board[0][i] = false;
        }
        
        return ret;
    }
    
    int backtracking(vector<vector<bool>>& board, int row, int col) {
        if(!checkValid(board, row, col))
            return 0;
        if(row == board.size() - 1) 
            return 1;

        int sum = 0;
        for(int i=0; i<board.size(); i++) {
            board[row+1][i] = true;
            sum += backtracking(board, row+1, i);
            board[row+1][i] = false;
        }
        
        return sum;
    }
    
    bool checkValid(vector<vector<bool>>& board, int row, int col) {
        int n = board.size();
        for(int i=0; i<n; i++) {
            if(i == row) continue;
            if(board[i][col]) {
                return false;
            }
        }
        
        for(int i=0; i<n; i++) {
            if(i == col) continue;
            if(board[row][i]) return false;
        }
    
        int i = row - 1, j = col + 1;
        while(i >= 0 && j < n) {
            if(board[i][j] == true) return false;
            i--;
            j++;
        }
        
        i = row + 1;
        j = col - 1;
        while(i < n && j >= 0) {
            if(board[i][j] == true) return false;
            i++;
            j--;
        }

        i = row - 1;
        j = col - 1;
        while(i >= 0 && j >= 0) {
            if(board[i][j] == true) return false;
            i--;
            j--;
        }
        
        i = row + 1;
        j = col + 1;
        while(i < n && j < n) {
            if(board[i][j] == true) return false;
            i++;
            j++;
        }
        
        return true;
        
    }
};