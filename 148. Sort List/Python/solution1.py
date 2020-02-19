# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        
        list_len, curr = 0, head
        while curr:
            list_len, curr = list_len + 1, curr.next
        
        new_head = head
        interval = 1
        while interval < list_len:
            left, right = new_head, new_head
            new_head, prev = None, None
            
            while right:
                left_idx, right_idx = 0, 0
                for j in range(interval):
                    right = right.next
                    if not right:
                        break
                
                while left_idx < interval and right_idx < interval and left and right:
                    if left.val <= right.val:
                        if not new_head:
                            new_head, prev = left, left
                        else:
                            prev.next = left
                            prev = prev.next
                        left_idx, left = left_idx + 1, left.next
                    else:
                        if not new_head:
                            new_head, prev = right, right
                        else:
                            prev.next = right
                            prev = prev.next
                        right_idx, right = right_idx + 1, right.next
                
                while left_idx < interval and left:
                    prev.next, left = left, left.next
                    left_idx, prev = left_idx + 1, prev.next
                while right_idx < interval and right:
                    prev.next, right = right, right.next
                    right_idx, prev = right_idx + 1, prev.next
                
                left = right
            
            prev.next = None
            interval *= 2
    
        return new_head


