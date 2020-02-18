// Node pointer map.
// Time: O(n), Space: O(n)

"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        old2new = {}
        
        curr = head
        while curr:
            old2new[curr] = Node(curr.val)
            curr = curr.next
        
        curr = head
        while curr:
            old2new[curr].next = old2new.get(curr.next, None)
            old2new[curr].random = old2new.get(curr.random, None)
            curr = curr.next
        
        return old2new[head] if head else None
