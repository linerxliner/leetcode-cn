# Complexity
#   Time: O(n)
#   Space: O(n)

class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        amount = 0
        min_amount = gas[0] - cost[0]
        min_idx = 0
        
        for i in range(len(gas)):
            amount += gas[i] - cost[i]
            if amount < min_amount:
                min_amount = amount
                min_idx = i
        
        return -1 if amount < 0 else (min_idx + 1) % len(gas)
