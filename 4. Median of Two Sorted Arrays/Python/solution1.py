# Complexity
#   Time: O(log(m + n))
#   Space: O(1)
# Description
#   Finds ((m + n + 1) / 2)-th number by eliminating half of existing numbers step by step.

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        total_len = len(nums1) + len(nums2)
        k = (total_len + 1) // 2

        while True:
            if len(nums1) == 0 or len(nums2) == 0:
                nums = nums1 if len(nums2) == 0 else nums2
                return nums[k - 1] if total_len % 2 else (nums[k - 1] + nums[k]) / 2
            elif k == 1:
                if total_len % 2:
                    return min(nums1[0], nums2[0])
                else:
                    nums1_2 = nums1[1] if len(nums1) > 1 else sys.maxsize
                    nums2_2 = nums2[1] if len(nums2) > 1 else sys.maxsize
                    return (min(nums1[0], nums2[0]) + min(max(nums1[0], nums2[0]), min(nums1_2, nums2_2))) / 2
            else:
                k1, k2 = min(len(nums1), k // 2), min(len(nums2), k // 2)
                if nums1[k1 - 1] < nums2[k2 - 1]:
                    k -= k1
                    nums1 = nums1[k1:]
                else:
                    k -= k2
                    nums2 = nums2[k2:]
