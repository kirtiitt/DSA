//i'm placing the queen column wise
class Solution {
private:
    void backtrack(int col, int n, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftR, vector<int> &upperD, vector<int> &lowerD) {
        if(col==n) {
            ans.push_back(board);
            return;
        }
        for(int row=0; row<n; row++) {
            if(!leftR[row] && !lowerD[row+col] && !upperD[n-1+ col-row]) {
                board[row][col]= 'Q';
                leftR[row]= 1;
                lowerD[row+col]= 1;
                upperD[n-1 +col-row]= 1;
                backtrack(col+1, n, board, ans, leftR, upperD, lowerD);
                board[row][col]= '.';
                leftR[row]= 0;
                lowerD[row+col]= 0;
                upperD[n-1+ col-row]= 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        string s(n, '.');
        for(int i=0; i<n; i++)
            board.push_back(s);
        vector<int> leftR(n, 0), upperD(2*n-1, 0), lowerD(2*n-1, 0);
        backtrack(0, n, board, ans, leftR, upperD, lowerD);
        return ans;
    }
};
