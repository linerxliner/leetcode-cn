// IDA*.
// Space: O(n)

class Solution:
    def IDA(self, coins, c_idx, amount, d, max_d):
        if amount == 0 or (amount % coins[c_idx] == 0 and d + amount // coins[c_idx] == max_d):
            return True
        elif amount < 0 or d >= max_d or d + amount // coins[c_idx] >= max_d:
            return False
        
        for i in range(c_idx, len(coins)):
            if self.IDA(coins, i, amount - coins[i], d + 1, max_d):
                return True
        
        return False
        
    def coinChange(self, coins: List[int], amount: int) -> int:
        coins.sort(reverse=True)
        
        for max_d in range(amount // coins[-1] + 1):
            if self.IDA(coins, 0, amount, 0, max_d):
                return max_d
        
        return -1
