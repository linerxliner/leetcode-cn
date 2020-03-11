# Complexity
#   Time: O(n * log(k))
#   Space: O(k)
# Description
#   Selects min list node from heapq.

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class HeapqEle(object):
    def __init__(self, ln):
        self.ln = ln

    def __lt__(self, other):
        return self.ln.val < other.ln.val

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        head = ListNode(0)
        curr = head

        hq = []
        for ln in lists:
            if ln:
                hq.append(HeapqEle(ln))
        heapq.heapify(hq)

        while len(hq) > 0:
            ln = heapq.heappop(hq).ln
            if ln.next:
                heapq.heappush(hq, HeapqEle(ln.next))
            curr.next = ln
            curr = curr.next

        return head.next
