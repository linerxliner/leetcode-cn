# Complexity
#   Time: O(n)
#   Space: O(1)

class Solution:
    MOD = 10 ** 9 + 7

    def distinctSubseqII(self, S: str) -> int:
        prev = {}
        cnt = 1

        for c in S:
            cnt, prev[c] = (cnt * 2 - prev.get(c, 0) + self.MOD) % self.MOD, cnt

        return cnt - 1
