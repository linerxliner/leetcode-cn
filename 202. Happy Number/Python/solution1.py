class Solution:
    def next_num(self, n):
        num = 0
        while n > 0:
            num += (n % 10) ** 2
            n //= 10
        return num
        
    def isHappy(self, n: int) -> bool:
        slow = n
        fast = self.next_num(n)
        
        while slow != fast:
            slow = self.next_num(slow)
            fast = self.next_num(self.next_num(fast))
        
        return slow == 1
