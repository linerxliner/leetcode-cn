# Complexity
#   Time: O(m * n)
#   Space: O(m * n)

class Solution:
    DIRS = ((-1, 0), (1, 0), (0, 1), (0, -1))

    def DFS(self, s_r, s_c):
        area = 0
        dq = collections.deque()

        self.visited[s_r][s_c] = True
        dq.append((s_r, s_c))

        while len(dq) > 0:
            r, c = dq.popleft()
            area += 1
            for d in self.DIRS:
                n_r, n_c = r + d[0], c + d[1]
                if 0 <= n_r < self.m and 0 <= n_c < self.n and not self.visited[n_r][n_c] and self.grid[n_r][n_c] == 1:
                    self.visited[n_r][n_c] = True
                    dq.append((n_r, n_c))

        return area

    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        self.m, self.n = len(grid), len(grid[0])
        self.grid = grid
        if self.m == 0 or self.n == 0:
            return 0

        self.visited = [[False] * self.n for _ in range(self.m)]

        max_area = 0

        for r in range(self.m):
            for c in range(self.n):
                if not self.visited[r][c] and self.grid[r][c] == 1:
                    max_area = max(max_area, self.DFS(r, c))

        return max_area
