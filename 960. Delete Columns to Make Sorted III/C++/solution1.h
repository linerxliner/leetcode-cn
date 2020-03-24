/* Complexity
 *   Time: O((W ^ 2) * N)
 *   Space: O(W)
 */

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int max_remain = 0;
        vector<int> dp(A[0].size(), 1);

        for (int i = 1; i < A[0].size(); ++i) {
            for (int j = 0; j < i; ++j) {
                bool success = true;

                for (auto& s: A) {
                    if (s[j] > s[i]) {
                        success = false;
                        break;
                    }
                }

                if (success) dp[i] = max(dp[i], dp[j] + 1);
            }
            max_remain = max(max_remain, dp[i]);
        }

        return A[0].size() - max_remain;
    }
};
