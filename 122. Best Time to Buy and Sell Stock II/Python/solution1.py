# Complexity
#   Time: O(n)
#   Space: O(1)

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0

        for i, p in enumerate(prices):
            if i > 0:
                max_profit += max(0, p - prices[i - 1])

        return max_profit
