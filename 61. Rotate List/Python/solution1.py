# Complexity
#   Time: O(n)
#   Space: O(1)

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        list_len = 0

        curr = head
        while curr:
            list_len += 1
            curr = curr.next

        if list_len == 0:
            return head
        k %= list_len
        if k == 0:
            return head

        early = head
        for _ in range(k):
            early = early.next
        late = head
        while early.next:
            late = late.next
            early = early.next

        early.next = head
        head = late.next
        late.next = None

        return head
