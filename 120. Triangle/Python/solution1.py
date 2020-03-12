# Complexity
#   Time: O(n ^ 2)
#   Space: O(n)

class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        if not triangle:
            return 0

        dp = triangle[-1][:]

        for row in triangle[-2::-1]:
            for i, n in enumerate(row):
                dp[i] = min(dp[i], dp[i + 1]) + n

        return dp[0]
