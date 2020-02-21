// Union Find.
// Time: O(n * log(n)), Space: O(n)

class Solution:
    class UnionFind(object):
        def __init__(self, n):
            self.parent = [i for i in range(n)]
            self.rank = [0] * n
            self.size = n
        
        def find(self, idx):
            while idx != self.parent[idx]:
                self.parent[idx] = self.parent[self.parent[idx]]
                idx = self.parent[idx]
            return idx
        
        def union(self, idx1, idx2):
            root1 = self.find(idx1)
            root2 = self.find(idx2)
            
            if root1 != root2:
                if self.rank[root1] < self.rank[root2]:
                    self.parent[root1] = root2
                elif self.rank[root1] > self.rank[root2]:
                    self.parent[root2] = root1
                else:
                    self.parent[root1] = root2
                    self.rank[root2] += 1
                self.size -= 1
            
    def numIslands(self, grid: List[List[str]]) -> int:
        if len(grid) == 0:
            return 0
        
        row_num, column_num = len(grid), len(grid[0])
        area_size = row_num * column_num
        union_find = self.UnionFind(area_size + 1)
        
        for r in range(row_num):
            for c in range(column_num):
                idx = r * column_num + c
                if grid[r][c] == '0':
                    union_find.union(idx, area_size)
                else:
                    if c + 1 < column_num and grid[r][c + 1] == '1':
                        union_find.union(idx, idx + 1)
                    if r + 1 < row_num and grid[r + 1][c] == '1':
                        union_find.union(idx, idx + column_num)
        
        return union_find.size - 1
