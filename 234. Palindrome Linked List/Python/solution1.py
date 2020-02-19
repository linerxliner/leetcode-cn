# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverse(self, head):
        prev = None
        curr = head
        succ = None
        
        while curr:
            succ = curr.next
            curr.next = prev
            prev = curr
            curr = succ
        
        return prev
        
    def isPalindrome(self, head: ListNode) -> bool:
        if not head:
            return True
        
        slow = head
        fast = head
        
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        
        tail = self.reverse(slow.next)
        curr1, curr2 = head, tail
        
        while curr2 and curr1.val == curr2.val:
            curr1 = curr1.next
            curr2 = curr2.next
            
        self.reverse(tail)
        
        return curr2 is None
