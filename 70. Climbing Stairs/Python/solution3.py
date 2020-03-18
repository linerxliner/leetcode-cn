# Complexity
#   Time: O(log(n))
#   Space: O(1)
# Description
#   Fabonacci general formula.

from math import sqrt

class Solution:
    def climbStairs(self, n: int) -> int:
        sqrt5 = sqrt(5)
        answer = (1 / sqrt5) * (((1 + sqrt5) / 2) ** (n + 1) - ((1 - sqrt5) / 2) ** (n + 1))

        return int(answer)
