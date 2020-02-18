// Follow new nodes.
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
        if not head:
            return None
        
        curr = head
        while curr:
            curr.next = Node(curr.val, next=curr.next)
            curr = curr.next.next
        
        curr = head
        while curr:
            if curr.random:
                curr.next.random = curr.random.next
            curr = curr.next.next
        
        new_head = head.next
        curr = head
        new_curr = curr.next
        while curr:
            curr.next = curr.next.next
            new_curr.next = new_curr.next.next if new_curr.next else None
            curr = curr.next
            new_curr = new_curr.next
        
        return new_head
