# Complexity
#   Time: O(n)
#   Space: O(1)

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        slow, fast = head.next if head else None, head.next.next if head and head.next else None

        if not slow or not fast:
            return None

        while slow is not fast:
            fast = fast.next.next if fast and fast.next else None
            if fast is None:
                return None
            slow = slow.next

        slow = head
        while slow is not fast:
            fast = fast.next
            slow = slow.next

        return slow

