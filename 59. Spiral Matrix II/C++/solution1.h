/* Complexity
 *   Time: O(n * n)
 *   Space: O(n * n)
 * Description
 *   General method in spiral matrix.
 */

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 0) return {};

        int up = 0, right = n - 1, down = n - 1, left = 0;
        int cnt = 0;
        vector<vector<int>> matrix(n, vector<int>(n));

        while (true) {
            for (int i = left; i <= right; ++i) matrix[up][i] = ++cnt;
            if (++up > down) break;
            for (int i = up; i <= down; ++i) matrix[i][right] = ++cnt;
            if (--right < left) break;
            for (int i = right; i >= left; --i) matrix[down][i] = ++cnt;
            if (--down < up) break;
            for (int i = down; i >= up; --i) matrix[i][left] = ++cnt;
            if (++left > right) break;
        }

        return matrix;
    }
};
