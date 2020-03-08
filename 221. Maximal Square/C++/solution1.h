/* Complexity
 *   Time: O(n * m)
 *   Space: O(m)
 */

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int left_up, tmp, max_edge = 0;
        vector<int> dp(matrix[0].size(), 0);
        
        for (int r = 0; r < matrix.size(); ++r) {
            left_up = 0;
            for (int c = 0; c < matrix[0].size(); ++c) {
                if (matrix[r][c] == '0') dp[c] = 0;
                else {
                    tmp = dp[c];
                    max_edge = max(max_edge, dp[c] = min(left_up, min(c > 0 ? dp[c - 1] : 0, dp[c])) + 1);
                    left_up = tmp;
                }

            }
        }
        
        return max_edge * max_edge;
    }
};
