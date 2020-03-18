# Complexity
#   Time: O((4 ^ n) / (n ^ (1 / 2)))
#   Space: O((4 ^ n) / (n ^ (3 / 2)))
# Description
#   Recursive generation.

class Solution:
    def r_generate(self, n, s, unmatched, unused):
        if unmatched == 0 and unused == 0:
            self.result.append(s)
            return

        if unmatched > 0:
            self.r_generate(n, s + ')', unmatched - 1, unused)

        if unused > 0:
            self.r_generate(n, s + '(', unmatched + 1, unused - 1)

    def generateParenthesis(self, n: int) -> List[str]:
        self.result = []
        self.r_generate(n, '', 0, n)

        return self.result
