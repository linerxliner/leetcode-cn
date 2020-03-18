# Complexity
#   Time: O(n ^ 2)
#   Space: O(n ^ 2)
# Description
#   Fills square matrix layer by layer.

class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        if n == 0:
            return []

        cnt = 0
        matrix = [[0] * n for _ in range(n)]

        for l in range(n // 2):
            for c in range(l, n - l - 1):
                cnt += 1
                matrix[l][c] = cnt
            for r in range(l, n - l - 1):
                cnt += 1
                matrix[r][n - 1 - l] = cnt
            for c in range(n - 1 - l, l, -1):
                cnt += 1
                matrix[n - 1 - l][c] = cnt
            for r in range(n - 1 - l, l, -1):
                cnt += 1
                matrix[r][l] = cnt

        if n % 2 == 1:
            matrix[n // 2][n // 2] = n ** 2

        return matrix
