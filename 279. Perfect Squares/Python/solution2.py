// BFS.
// Time: O(n^(3/2)), Space: O(n)

class Solution:            
    def numSquares(self, n: int) -> int:
        visited = set()
        deq = collections.deque()
        
        turn = 1
        deq.append(n)
        
        while len(deq) > 0:
            deq_len = len(deq)
            
            for _ in range(deq_len):
                m = deq.popleft()
                
                for k in range(int(math.sqrt(m)), 0, -1):
                    num = m - k * k
                    
                    if num == 0:
                        return turn
                    elif num > 0 and num not in visited:
                        visited.add(num)
                        deq.append(num)
            
            turn += 1
        
        return 0
