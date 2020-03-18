# Complexity
#   Time: O(n ^ 2)
#   Space: O(n ^ 2)
# Description
#   General method to travel spiral matrix.

class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        if n == 0:
            return []

        cnt = 0
        matrix = [[0] * n for _ in range(n)]
        up, right, down, left = 0, n - 1, n - 1, 0

        while cnt <= n ** 2:
            for c in range(left, right + 1):
                cnt += 1
                matrix[up][c] = cnt
            up += 1
            if up > down:
                break

            for r in range(up, down + 1):
                cnt += 1
                matrix[r][right] = cnt
            right -= 1
            if right < left:
                break

            for c in range(right, left - 1, -1):
                cnt += 1
                matrix[down][c] = cnt
            down -= 1
            if down < up:
                break

            for r in range(down, up - 1, -1):
                cnt += 1
                matrix[r][left] = cnt
            left += 1
            if left > right:
                break

        return matrix
