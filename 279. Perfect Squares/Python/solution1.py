// DFS with pruning。
// Space: O(n)

class Solution:
    def dfs(self, n, k, d):
        if d >= self.min_cnt or n < 0:
            return
        
        if n == 0:
            self.min_cnt = min(self.min_cnt, d)

        for i in range(k, 0, -1):
            self.dfs(n - i * i, i, d + 1)
            
    def numSquares(self, n: int) -> int:
        self.min_cnt = n
        
        self.dfs(n, int(math.sqrt(n)), 0)
        
        return self.min_cnt
