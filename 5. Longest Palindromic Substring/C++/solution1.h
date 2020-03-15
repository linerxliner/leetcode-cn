/* Complexity
 *   Time: O(n ^ 2)
 *   Space: O(n ^ 2)
 * Description
 *   DP.
 */

class Solution {
public:
    string longestPalindrome(string s) {
        int max_len = 0, max_len_l = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

        for (int r = 0; r < s.size(); ++r) {
            for (int l = 0; l <= r; ++l) {
                if (s[l] == s[r] && ((r - l + 1) <= 3 || dp[l + 1][r - 1])) {
                    dp[l][r] = true;
                    if (r - l + 1 > max_len) {
                        max_len = r - l + 1;
                        max_len_l = l;
                    }
                }
            }
        }

        return s.substr(max_len_l, max_len);
    }
};
