# Complexity
#   Time: O(min(m, n))
#   Space: O(1)
# Description
#   Combination.

class Solution:
    def combination(self, m, n):
        m = min(m, n - m)
        result = 1

        for i in range(n - m + 1, n + 1):
            result *= i
        for i in range(2, m + 1):
            result //= i

        return result

    def uniquePaths(self, m: int, n: int) -> int:
        return self.combination(m - 1, m + n - 2)
