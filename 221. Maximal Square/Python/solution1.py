# Complexity
#   Time: O(m * n)
#   Space: O(n)

class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        m, n = len(matrix), len(matrix[0]) if len(matrix) > 0 else 0
        if m == 0 or n == 0:
            return 0

        dp = [0] * n
        max_edge = 0

        for r in range(m):
            right_up = 0

            for c in range(n):
                if matrix[r][c] == '1':
                    t = dp[c]
                    dp[c] = min(right_up, min(0 if c == 0 else dp[c - 1], dp[c])) + 1
                    max_edge = max(max_edge, dp[c])
                    right_up = t
                else:
                    dp[c] = 0

        return max_edge * max_edge
