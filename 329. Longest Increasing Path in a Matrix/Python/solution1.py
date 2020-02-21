// DP and BFS.
// Time: O(n), Space: O(n)

class Solution:
    DIR = ((-1, 0), (0, 1), (1, 0), (0, -1))
    
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        if len(matrix) == 0:
            return 0
        
        row_num, column_num = len(matrix), len(matrix[0])
        out_degrees = [[0] * column_num for _ in range(row_num)]
        
        for r in range(row_num):
            for c in range(column_num):
                for d in self.DIR:
                    n_r, n_c = r + d[0], c + d[1]
                    if n_r >= 0 and n_r < row_num and n_c >= 0 and n_c < column_num and matrix[n_r][n_c] > matrix[r][c]:
                        out_degrees[r][c] += 1
        
        deq = collections.deque()
        
        for r in range(row_num):
            for c in range(column_num):
                if out_degrees[r][c] == 0:
                    deq.append((r, c))
        
        longest = 0
        while len(deq) > 0:
            deq_size = len(deq)
            for _ in range(deq_size):
                r, c = deq.popleft()
                for d in self.DIR:
                    n_r, n_c = r + d[0], c + d[1]
                    if n_r >= 0 and n_r < row_num and n_c >= 0 and n_c < column_num and matrix[n_r][n_c] < matrix[r][c]:
                        out_degrees[n_r][n_c] -= 1
                        if out_degrees[n_r][n_c] == 0:
                            deq.append((n_r, n_c))
            longest += 1
        
        return longest
