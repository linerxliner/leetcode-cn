# Complexity
#   Time: O(n * log(n))
#   Space: O(n)

from functools import cmp_to_key
from bisect import bisect_left

class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        envelopes.sort(key=lambda e: (e[0], -e[1]))
        dp = []

        for h in map(lambda e: e[1], envelopes):
            i = bisect_left(dp, h)
            if i == len(dp):
                dp.append(h)
            elif h < dp[i]:
                dp[i] = h

        return len(dp)
