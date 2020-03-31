/* Compelxity
 *   Time: O(1)
 *   Space: O(1)
 */

class Solution {
public:
    const int kSize = 9;

    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[kSize][kSize], colums[kSize][kSize], blocks[kSize][kSize];

        memset(rows, false, sizeof(rows));
        memset(colums, false, sizeof(colums));
        memset(blocks, false, sizeof(blocks));

        for (int r = 0; r < kSize; ++r) {
            for (int c = 0; c < kSize; ++c) {
                char num = board[r][c];
                if (num != '.') {
                    if (rows[r][num - '1'] || colums[c][num - '1'] || blocks[r / 3 * 3 + c / 3][num - '1']) return false;
                    else rows[r][num - '1'] = colums[c][num - '1'] = blocks[r / 3 * 3 + c / 3][num - '1'] = true;
                }
            }
        }

        return true;
    }
};
