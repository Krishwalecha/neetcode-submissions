class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> rows(9, 0);
        vector<int> cols(9, 0);
        vector<int> sqs(9, 0);

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') {
                    int val = board[r][c] - '1';

                    if ((rows[r] & 1 << val) || (cols[c] & 1 << val) ||
                        (sqs[(r / 3) * 3 + (c / 3)] & 1 << val))
                        return false;

                    rows[r] |= (1 << val);
                    cols[c] |= (1 << val);
                    sqs[(r / 3) * 3 + (c/ 3)] |= (1 << val);
                }
            }
        }

        return true;
    }
};
