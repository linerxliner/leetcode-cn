/* Complexity
 *   Time: O(n ^ 2)
 *   Space: O(1)
 * Description.
 *   Rotates image layer by layer.
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), t;

        for (int l = 0; l < n / 2; ++l) {
            for (int c = l; c < n - 1 - l; ++c) {
                t = matrix[l][c];
                matrix[l][c] = matrix[n - 1 - c][l];
                matrix[n - 1 - c][l] = matrix[n - 1 - l][n - 1 -c];
                matrix[n - 1 - l][n - 1 -c] = matrix[c][n - 1 - l];
                matrix[c][n - 1 - l] = t;
            }
        }
    }
};
