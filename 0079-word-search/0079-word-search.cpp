class Solution {
public:
    bool solve(int row, int col, int index,
               vector<vector<char>>& board, string& word) {
        
        // Entire word has been found
        if (index == word.size()) {
            return true;
        }

        int m = board.size();
        int n = board[0].size();

        // Invalid cell or character does not match
        if (row < 0 || row >= m ||
            col < 0 || col >= n ||
            board[row][col] != word[index]) {
            return false;
        }

        // Mark current cell as visited
        char original = board[row][col];
        board[row][col] = '#';

        // Search for the next character
        bool found =
            solve(row - 1, col, index + 1, board, word) ||
            solve(row + 1, col, index + 1, board, word) ||
            solve(row, col - 1, index + 1, board, word) ||
            solve(row, col + 1, index + 1, board, word);

        // Backtrack
        board[row][col] = original;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        // Try every cell as the starting position
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (solve(row, col, 0, board, word)) {
                    return true;
                }
            }
        }

        return false;
    }
};