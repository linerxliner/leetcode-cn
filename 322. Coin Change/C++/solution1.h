// DP.
// Time: O(kn), Space: O(n)

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        
        sort(coins.begin(), coins.end());
        
        dp[0] = 0;
        for (int n = 1; n <= amount; ++n) {
            for (auto c: coins) {
                if (n - c < 0) break;
                else if (dp[n - c] != -1) {
                    if (dp[n] == -1) dp[n] = dp[n - c] + 1;
                    else dp[n] = min(dp[n], dp[n - c] + 1);
                }
            }
        }
        
        return dp[amount];
    }
};
