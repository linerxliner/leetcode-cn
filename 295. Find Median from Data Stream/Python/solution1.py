// Two heaps.
// Time: O(logn), Space: O(n)

class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.max_heap = []
        self.min_heap = []

    def addNum(self, num: int) -> None:
        heapq.heappush(self.min_heap, num)
        min_top = heapq.heappop(self.min_heap)
        heapq.heappush(self.max_heap, -min_top)
        
        if len(self.max_heap) > len(self.min_heap):
            max_top = -heapq.heappop(self.max_heap)
            heapq.heappush(self.min_heap, max_top)

    def findMedian(self) -> float:
        if len(self.max_heap) < len(self.min_heap):
            return self.min_heap[0]
        else:
            return (self.min_heap[0] + -self.max_heap[0]) / 2

# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
