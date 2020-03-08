/* Complexity
 *   Time: O(n ^ 2)
 *   Space: O(n)
 */

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.back());
        
        for (int r = triangle.size() - 2; r >= 0; --r) {
            for (int c = 0; c < triangle[r].size(); ++c) {
                dp[c] = min(dp[c], dp[c + 1]) + triangle[r][c];
            }
        }
        
        return dp[0];
    }
};
