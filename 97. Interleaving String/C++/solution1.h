/* Complexity
 *   Time: O(m * n)
 *   Space: O(min(m, n))
 * Description
 *   DP.
 */

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() < s2.size()) return isInterleave(s2, s1, s3);
        if (s1.size() + s2.size() != s3.size()) return false;

        vector<bool> dp(s2.size() + 1, false);

        for (int r = 0; r <= s1.size(); ++r) {
            for (int c = 0; c <= s2.size(); ++c) {
                if (r == 0 && c == 0) dp[c] = true;
                else if (r == 0) dp[c] = dp[c - 1] && s2[c - 1] == s3[r + c - 1];
                else if (c == 0) dp[c] = dp[c] && s1[r - 1] == s3[r + c - 1];
                else dp[c] = (dp[c - 1] && s2[c - 1] == s3[r + c - 1]) || (dp[c] && s1[r - 1] == s3[r + c - 1]);
            }
        }

        return dp[s2.size()];
    }
};
