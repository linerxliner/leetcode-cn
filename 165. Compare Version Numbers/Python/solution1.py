# Complexity
#   Time: O(n)
#   Space: O(n)

class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1, v2 = list(map(int, version1.split('.'))), list(map(int, version2.split('.')))

        while len(v1) > 0 and v1[-1] == 0:
            v1.pop()
        while len(v2) > 0 and v2[-1] == 0:
            v2.pop()

        for i in range(max(len(v1), len(v2))):
            if i >= len(v1) and i < len(v2):
                return -1
            elif i < len(v1) and i >= len(v2):
                return 1

            if v1[i] < v2[i]:
                return -1
            elif v1[i] > v2[i]:
                return 1

        return 0
