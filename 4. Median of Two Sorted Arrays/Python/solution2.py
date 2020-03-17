# Complexity
#   Time: O(log(min(m, n)))
#   Space: O(1)
# Description
#   Divides two list into four parts and balances them according to medium elements.

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            return self.findMedianSortedArrays(nums2, nums1)

        len1, len2 = len(nums1), len(nums2)
        if len1 == 0:
            return nums2[len2 // 2] if len2 % 2 else (nums2[len2 // 2 - 1] + nums2[len2 // 2]) / 2
        lo, hi = 0, len1

        while lo <= hi:
            mi1 = (lo + hi) // 2
            mi2 = (len1 + len2 + 1) // 2 - mi1

            if mi1 > 0 and nums1[mi1 - 1] > nums2[mi2]:
                hi = mi1 - 1
            elif mi1 < len1 and nums1[mi1] < nums2[mi2 - 1]:
                lo = mi1 + 1
            else:
                l1, l2 = nums1[mi1 - 1] if mi1 > 0 else -sys.maxsize, nums2[mi2 - 1] if mi2 > 0 else -sys.maxsize

                if (len1 + len2) % 2:
                    return max(l1, l2)
                else:
                    r1, r2 = nums1[mi1] if mi1 < len1 else sys.maxsize, nums2[mi2] if mi2 < len2 else sys.maxsize
                    return (max(l1, l2) + min(r1, r2)) / 2
