class Solution {
public:

    // Check whether it is safe to place digit d at board[row][col]
    bool isValid(vector<vector<char>>& board, int row, int col, char d) {

        for (int i = 0; i < 9; i++) {

            // Check row
            if (board[row][i] == d)
                return false;

            // Check column
            if (board[i][col] == d)
                return false;

            // Check 3x3 sub-box
            int subRow = 3 * (row / 3) + i / 3;
            int subCol = 3 * (col / 3) + i % 3;

            if (board[subRow][subCol] == d)
                return false;
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {

        // Traverse every cell
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                // Find an empty cell
                if (board[i][j] == '.') {

                    // Try digits from 1 to 9
                    for (char d = '1'; d <= '9'; d++) {

                        if (isValid(board, i, j, d)) {

                            // Place the digit
                            board[i][j] = d;

                            // Recursively solve remaining board
                            if (solve(board))
                                return true;

                            // Backtrack if solution not found
                            board[i][j] = '.';
                        }
                    }

                    // No digit can be placed here
                    return false;
                }
            }
        }

        // All cells are filled successfully
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};