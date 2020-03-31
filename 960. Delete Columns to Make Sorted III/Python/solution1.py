# Complexity
#   Time: O(n * (w ^ 2))
#   Space: O(w)

class Solution:
    def check(self, A, prev, curr):
        for s in A:
            if s[prev] > s[curr]:
                return False

        return True

    def minDeletionSize(self, A: List[str]) -> int:
        max_remain = 1
        dp = [1] * len(A[0])

        for i in range(1, len(A[0])):
            for j in range(0, i):
                if self.check(A, j, i):
                    dp[i] = max(dp[i], dp[j] + 1)
            max_remain = max(max_remain, dp[i])

        return len(A[0]) - max_remain
