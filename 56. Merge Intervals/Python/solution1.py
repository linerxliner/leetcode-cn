# Complexity
#   Time: O(n)
#   Space: O(n)

from functools import cmp_to_key

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) == 0:
            return []

        result = []

        intervals.sort(key=cmp_to_key(lambda x, y: x[0] - y[0] if x[0] != y[0] else x[1] - y[1]))

        result.append(intervals[0])
        for interval in intervals[1:]:
            if interval[0] <= result[-1][1]:
                result[-1][1] = max(result[-1][1], interval[1])
            else:
                result.append(interval)

        return result
