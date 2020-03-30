# Complexity
#   Time: O(n * log(sum(nums)))
#   Space: O(1)
# Description
#   Binary search of min upper bound to make list m intervals.

class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        lo, hi = max(nums), sum(nums)

        while lo < hi:
            mi = (lo + hi) // 2

            t, cnt = 0, 1
            for n in nums:
                t += n
                if t > mi:
                    cnt += 1
                    t = n

            if cnt > m:
                lo = mi + 1
            else:
                hi = mi

        return lo
