/* Complexity
 *   Time: O(4 ^ n /(n ^ (1 / 2)))
 *   Space: O(4 ^ n /(n ^ (1 / 2)))
 * Description
 *   DP.
 */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        map<int, vector<string>> dp;

        dp[0] = vector<string>({""});

        for (int k = 1; k <= n; ++k) {
            dp[k] = vector<string>();
            for (int i = 0; i < k; ++i) {
                for (const auto& s1: dp[i]) {
                    for (const auto& s2: dp[k - i - 1]) {
                        dp[k].push_back("(" + s1 + ")" + s2);
                    }
                }
            }
        }

        return dp[n];
    }
};
