# Complexity
#   Time: O(m * n)
#   Space: O(min(m, n))
# Description
#   DP.

from collections import Counter

class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s1) < len(s2):
            return self.isInterleave(s2, s1, s3)

        if Counter(s1) + Counter(s2) != Counter(s3):
            return False

        dp = [True] * (len(s2) + 1)

        for i in range(len(s1) + 1):
            for j in range(len(s2) + 1):
                if i == 0 and j != 0:
                    dp[j] = dp[j - 1] and s2[j - 1] == s3[i + j - 1]
                elif i != 0 and j == 0:
                    dp[j] = dp[j] and s1[i - 1] == s3[i + j - 1]
                elif i != 0 and j != 0:
                    dp[j] = (dp[j - 1] and s2[j - 1] == s3[i + j - 1]) or (dp[j] and s1[i - 1] == s3[i + j - 1])

        return dp[-1]
