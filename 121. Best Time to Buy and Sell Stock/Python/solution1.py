# Complexity
#   Time: O(n)
#   Space: O(1)

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 0:
            return 0

        max_profit = 0
        min_price = prices[0]

        for p in prices[1:]:
            min_price = min(min_price, p)
            max_profit = max(max_profit, p - min_price)

        return max_profit
