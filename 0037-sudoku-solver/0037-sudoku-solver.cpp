class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char digit) {
        for (int i = 0; i < 9; i++) {
            // Check the row
            if (board[row][i] == digit) {
                return false;
            }

            // Check the column
            if (board[i][col] == digit) {
                return false;
            }

            // Check the corresponding 3x3 box
            int boxRow = 3 * (row / 3) + i / 3;
            int boxCol = 3 * (col / 3) + i % 3;

            if (board[boxRow][boxCol] == digit) {
                return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {

                if (board[row][col] == '.') {

                    for (char digit = '1'; digit <= '9'; digit++) {

                        if (isValid(board, row, col, digit)) {
                            // Choose
                            board[row][col] = digit;

                            // Explore
                            if (solve(board)) {
                                return true;
                            }

                            // Backtrack
                            board[row][col] = '.';
                        }
                    }

                    // No digit works for this empty cell
                    return false;
                }
            }
        }

        // No empty cell remains
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};