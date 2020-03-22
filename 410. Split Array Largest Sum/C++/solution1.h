/* Complexity
 *   Time: O(n * (n - m) ^ 2)
 *   Space: O(n)
 * Description
 *   DP.
 */

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        vector<int> dp(nums.size() + 1, INT_MAX);

        dp[0] = 0;
        for (int j = 1; j <= 1 + nums.size() - m; ++j) dp[j] = dp[j - 1] + nums[j - 1];

        for (int i = 2; i <= m; ++i) {
            for (int j = i + nums.size() - m; j >= i; --j) {
                int num_sum = 0;

                for (int k = 1; k <= j - i + 1; ++k) {
                    num_sum += nums[j - k];
                    dp[j] = min(dp[j], max(dp[j - k], num_sum));
                }
            }
        }

        return dp[nums.size()];
    }
};
