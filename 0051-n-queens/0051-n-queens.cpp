class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n) {
        // Check the same column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        int i = row - 1;
        int j = col - 1;

        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q')
                return false;

            i--;
            j--;
        }

        // Check upper-right diagonal
        i = row - 1;
        j = col + 1;

        while (i >= 0 && j < n) {
            if (board[i][j] == 'Q')
                return false;

            i--;
            j++;
        }

        return true;
    }

    void solve(int row, vector<string>& board,
               vector<vector<string>>& answer, int n) {

        // All rows have received one queen
        if (row == n) {
            answer.push_back(board);
            return;
        }

        // Try placing a queen in every column
        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board, n)) {
                // Choose
                board[row][col] = 'Q';

                // Explore the next row
                solve(row + 1, board, answer, n);

                // Undo the choice
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> answer;
        vector<string> board(n, string(n, '.'));

        solve(0, board, answer, n);

        return answer;
    }
};