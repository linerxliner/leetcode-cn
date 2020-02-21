// BFS.
// Time: (k * n); Space: O(n)

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0:
            return 0
        
        deq = collections.deque()
        visited = set()
        
        coins.sort()
        deq.append(amount)
        visited.add(amount)
        
        turn = 1
        while len(deq) > 0:
            deq_size = len(deq)
            
            for _ in range(deq_size):
                m = deq.popleft()
                for c in coins:
                    r = m - c
                    if r == 0:
                        return turn
                    elif r > 0 and r not in visited:
                        deq.append(r)
                        visited.add(r)
                    elif r < 0:
                        break
        
            turn += 1
        
        return -1
