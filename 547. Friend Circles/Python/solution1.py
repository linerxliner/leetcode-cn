# Complexity
#   Time: O((n ^ 2) * log(n))
#   Space: O(n)

class UnionFind(object):
    def __init__(self, size):
        self._parent = [i for i in range(size)]
        self._rank = [0] * size
        self._union_num = size

    def find(self, u):
        while u != self._parent[u]:
            self._parent[u] = self._parent[self._parent[u]]
            u = self._parent[u]

        return u

    def union(self, u, v):
        p_u, p_v = self.find(u), self.find(v)

        if p_u != p_v:
            if self._rank[u] < self._rank[v]:
                self._parent[p_u] = p_v
            elif self._rank[u] > self._rank[v]:
                self._parent[p_v] = p_u
            else:
                self._parent[p_u] = p_v
                self._rank[p_v] += 1
            self._union_num -= 1

    @property
    def union_num(self):
        return self._union_num

class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        num = len(M)
        union_find = UnionFind(num)

        for u in range(num):
            for v in range(u + 1, num):
                if M[u][v]:
                    union_find.union(u, v)

        return union_find.union_num
