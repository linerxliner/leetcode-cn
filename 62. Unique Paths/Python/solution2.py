# Complexity
#   Time: O(m * n)
#   Space: O(min(m, n))
# Description
#   DP.

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        row_num, column_num = max(m, n), min(m, n)
        dp = [0] * column_num
        dp[0] = 1

        for _ in range(row_num):
            for i in range(1, column_num):
                dp[i] += dp[i - 1]

        return dp[column_num - 1]
