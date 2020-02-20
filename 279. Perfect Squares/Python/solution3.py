// DP.
// Time: O(n * sqrt(n)), Space: O(n)

class Solution:
    def numSquares(self, n: int) -> int:
        dp = [0]
        
        for i in range(1, n + 1):
            dp.append(dp[i - 1] + 1)
            x = 2
            while x * x <= i:
                dp[i] = min(dp[i], dp[i - x * x] + 1)
                x += 1
        
        return dp[n]
