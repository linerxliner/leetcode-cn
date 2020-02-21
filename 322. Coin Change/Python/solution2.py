// DFS.
// Space: O(n).

class Solution:
    def DFS(self, coins, c_idx, amount, d):
        if d >= self.min_coin_num or amount < 0 or d + amount // coins[c_idx] >= self.min_coin_num:
            return
        
        if amount == 0:
            self.min_coin_num = min(self.min_coin_num, d)
            return
        elif amount % coins[c_idx] == 0:
            self.min_coin_num = min(self.min_coin_num, d + amount // coins[c_idx])
            return
        
        for i in range(c_idx, len(coins)):
            self.DFS(coins, i, amount - coins[i], d + 1)
            
    def coinChange(self, coins: List[int], amount: int) -> int:
        coins.sort(reverse=True)
        self.min_coin_num = amount + 1
        self.DFS(coins, 0, amount, 0)
        
        return self.min_coin_num if self.min_coin_num <= amount else -1
