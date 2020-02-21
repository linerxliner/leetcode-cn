// BFS.
// Time: O(n); Space(n)

class Solution:
    DIR = ((-1, 0), (0, 1), (1, 0), (0, -1))
    
    def numIslands(self, grid: List[List[str]]) -> int:
        if len(grid) == 0:
            return 0
        
        cnt = 0
        row_num, column_num = len(grid), len(grid[0])
        visited = [[False] * column_num for _ in range(row_num)]
        
        for r in range(row_num):
            for c in range(column_num):
                if grid[r][c] == '1' and not visited[r][c]:
                    cnt += 1
                    deq = collections.deque()
                    visited[r][c] = True
                    deq.append((r, c))
                    while len(deq) > 0:
                        curr_r, curr_c = deq.popleft()
                        for d in self.DIR:
                            n_r, n_c = curr_r + d[0], curr_c + d[1]
                            if 0 <= n_r < row_num and 0 <= n_c < column_num and grid[n_r][n_c] == '1' and not visited[n_r][n_c]:
                                visited[n_r][n_c] = True
                                deq.append((n_r, n_c))
        
        return cnt
