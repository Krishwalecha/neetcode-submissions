class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row
        for (int row = 0; row < 9; row++) {
            unordered_set<char> seen;
            for (int col = 0; col < 9; col++) {
                if (board[row][col] != '.') {
                    if (seen.count(board[row][col])) return false;
                    seen.insert(board[row][col]);
                }
            }
        }

        // column
        for (int col = 0; col < 9; col++) {
            unordered_set<char> seen;
            for (int i = 0; i < 9; i++) {
                if (!(board[i][col] == '.')) {
                    if (seen.count(board[i][col])) return false;
                    seen.insert(board[i][col]);
                }
            }
        }

        // 3x3 matrix
        for (int square = 0; square < 9; square++) {
            unordered_set<char> seen;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int row = (square / 3) * 3 + i;
                    int col = (square % 3) * 3 + j;
                    if (!(board[row][col] == '.')) {
                        if (seen.count(board[row][col])) return false;
                        seen.insert(board[row][col]);
                    }
                }
            }
        }

        return true;
    }
};
