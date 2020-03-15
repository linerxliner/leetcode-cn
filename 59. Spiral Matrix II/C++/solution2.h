/* Complexity
 *   Time: O(n ^ 2)
 *   Space: O(n ^ 2)
 * Description
 *   Special method in symmetric matrix.
 */

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 0) return {};

        int cnt = 0;
        vector<vector<int>> matrix(n, vector<int>(n));

        for (int l = 0; l < n / 2; ++l) {
            for (int c = l; c < n - 1 - l; ++c) matrix[l][c] = ++cnt;
            for (int r = l; r < n - 1 - l; ++r) matrix[r][n - 1 - l] = ++cnt;
            for (int c = n - 1 - l; c > l; --c) matrix[n - 1 - l][c] = ++cnt;
            for (int r = n - 1 -l; r > l; --r) matrix[r][l] = ++cnt;
        }

        if (n % 2) matrix[n / 2][n / 2] = ++cnt;

        return matrix;
    }
};
