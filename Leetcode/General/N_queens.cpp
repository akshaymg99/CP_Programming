/*
Problem link: https://leetcode.com/problems/n-queens/
N Queens: Placing queens in chessboard so that they won't attack each other
*/

class Solution {
private:
    vector<vector<string>> res;
    bool isValid(vector<string>&board, int row, int col) {
        for (int i=0; i<row; ++i) 
            if (board[i][col] == 'Q')
                return false;
        for (int i=row,j=col; i>=0 && j>=0; --i,--j)
            if (board[i][j] == 'Q')
                return false;
        for (int i=row, j=col; i>=0 && j<board.size(); --i,++j)
            if (board[i][j] == 'Q')
                return false;
            
        return true;
    }
    
    void dfs(vector<string>&board, int row) {
        if (row == board.size()) {
            res.push_back(board);
            return;
        }
        for (int j=0; j<board.size(); ++j) {
            
            if (isValid(board, row, j)) {
                board[row][j] = 'Q';
                dfs(board, row+1);
                board[row][j] = '.';
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string>  board(n, string(n, '.'));
        dfs(board, 0);
        return res;
    }
};