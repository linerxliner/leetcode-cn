# Complexity
#   Time: O(max(m, n))
#   Time: O(max(m, n))

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        l3 = ListNode(0)
        curr = l3

        while l1 or l2:
            v1, v2 = 0, 0
            if l1:
                v1 = l1.val
                l1 = l1.next
            if l2:
                v2 = l2.val
                l2 = l2.next
            v3 = v1 + v2 + curr.val

            curr.val = v3 % 10
            if v3 // 10 != 0 or l1 or l2:
                curr.next = ListNode(v3 // 10)

            curr = curr.next

        return l3
