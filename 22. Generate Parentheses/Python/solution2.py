# Complexity
#   Time: O((4 ^ n) / (n ^ (1 / 2)))
#   Space: O((4 ^ n) / (n ^ (1 / 2)))
# Description
#   DP.

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        dp = [[] for _ in range(n + 1)]
        dp[0].append('')

        for k in range(1, n + 1):
            for i in range(k):
                for p1 in dp[i]:
                    for p2 in dp[k - 1 - i]:
                        dp[k].append('({}){}'.format(p1, p2))

        return dp[n]
