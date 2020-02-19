# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        prev = None
        curr = head
        succ = None
        
        while curr:
            succ = curr.next
            curr.next = prev
            prev = curr
            curr = succ
        
        return prev
