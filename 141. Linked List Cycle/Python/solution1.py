# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if not head or not head.next:
            return False
        
        slow = head
        fast = head.next.next
        
        while slow != fast and fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        return slow is fast
        
