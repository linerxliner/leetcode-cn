/* Complexity
 *   Time: O(n ^ 2)
 *   Space: O(1)
 * Description
 *   Transposes and reverses matrix.
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int r = 0; r < n - 1; ++r) {
            for (int c = r + 1; c < n; ++c) {
                swap(matrix[r][c], matrix[c][r]);
            }
        }

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n / 2; ++c) {
                swap(matrix[r][c], matrix[r][n - 1 -c]);
            }
        }
    }
};
