# Complexity
#   Time: O(m * n)
#   Space: O(m * n)

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix or not matrix[0]:
            return []

        row_num, column_num = len(matrix), len(matrix[0])
        up, right, down, left = 0, column_num - 1, row_num - 1, 0
        result = []

        while True:
            result.extend(matrix[up][left:right + 1])
            up += 1
            if up > down:
                break
            result.extend([column[right] for column in matrix[up:down + 1]])
            right -= 1
            if right < left:
                break
            result.extend(reversed(matrix[down][left:right + 1]))
            down -= 1
            if down < up:
                break
            result.extend(reversed([column[left] for column in matrix[up:down + 1]]))
            left += 1
            if left > right:
                break

        return result
