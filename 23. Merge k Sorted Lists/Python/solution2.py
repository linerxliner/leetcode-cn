# Complexity
#   Time: O(n * log(k))
#   Space: O(k)
# Description
#   Binary merge in several linked list.

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
from collections import deque

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        dq = deque()
        for ln in lists:
            if ln:
                dq.append(ln)

        while len(dq) > 1:
            dq_len = len(dq)
            while dq_len > 0:
                ln1 = dq.popleft()
                dq_len -= 1
                if dq_len > 0:
                    ln2 = dq.popleft()
                    dq_len -= 1
                else:
                    dq.append(ln1)
                    break

                ln3 = ListNode(0)
                curr = ln3
                while ln1 and ln2:
                    if ln1.val <= ln2.val:
                        curr.next = ln1
                        ln1 = ln1.next
                    else:
                        curr.next = ln2
                        ln2 = ln2.next
                    curr = curr.next
                if ln1:
                    curr.next = ln1
                else:
                    curr.next = ln2

                dq.append(ln3.next)

        return dq.popleft() if dq else None
