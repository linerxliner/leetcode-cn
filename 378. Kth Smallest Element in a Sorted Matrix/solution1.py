class Solution:
    def less_equal_count(self, matrix, value):
        cnt = 0
        r = 0
        c = len(matrix[0]) - 1
        
        while r < len(matrix) and c >= 0:
            if matrix[r][c] < value:
                cnt += c + 1
                r += 1
            else:
                c -= 1
        
        return cnt

    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        lo = matrix[0][0]
        hi = matrix[-1][-1]
        
        while lo < hi:
            mi = (lo + hi + 1) // 2
            cnt = self.less_equal_count(matrix, mi)
            if cnt < k:
                lo = mi
            else:
                hi = mi - 1
        
        return lo
