class Solution {
public:
    bool sudoku(vector<vector<char>> &board){
        for(int i=0; i<9; i++)  //row
            for(int j=0; j<9; j++)  //column
                if(board[i][j]=='.') {  //empty?
                    for(char c='1'; c<='9'; c++)
                        if(isvalid(board, i, j, c)) {
                            board[i][j]=c;
                            if(sudoku(board)==true)  return true;
                            else  board[i][j]='.';
                        }
                    return false;  //no number entered
                }
        return true;
    }

    bool isvalid(vector<vector<char>> &board, int row, int col, char c) {
        for(int i=0; i<9; i++)  //for row, col and 3* 3 board
            if(board[row][i]==c || board[i][col]==c || board[3*(row/3)+ i/3][3*(col/3)+ i%3]==c)
                return false;
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        sudoku(board);
    }
};
