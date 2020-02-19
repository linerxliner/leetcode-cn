# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if not head or not head.next or not head.next.next:
            return head
        
        odd_head = head
        even_head = head.next
        odd_prev = odd_head
        even_prev = even_head
        curr = head.next.next
        
        while curr:
            odd_prev.next = curr
            odd_prev = odd_prev.next
            even_prev.next = curr.next
            even_prev = even_prev.next
            curr = curr.next.next if curr.next else None
        
        odd_prev.next = even_head
        
        return odd_head
        
