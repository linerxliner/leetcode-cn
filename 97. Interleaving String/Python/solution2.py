# Complexity
#   Time: O(m * n)
#   Space: O(m * n)
# Decription
#   BFS.

from collections import deque

class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if Counter(s1) + Counter(s2) != Counter(s3):
            return False

        visited = [[False] * (len(s2) + 1) for _ in range(len(s1) + 1)]
        dq = deque()

        visited[0][0] = True
        dq.append((0, 0))

        while len(dq) != 0:
            r, c = dq.popleft()

            if r == len(s1) and c == len(s2):
                return True
            if r + 1 <= len(s1) and not visited[r + 1][c] and s1[r] == s3[r + c]:
                visited[r + 1][c] = True
                dq.append((r + 1, c))
            if c + 1 <= len(s2) and not visited[r][c + 1] and s2[c] == s3[r + c]:
                visited[r][c + 1] = True
                dq.append((r, c + 1))


        return False
