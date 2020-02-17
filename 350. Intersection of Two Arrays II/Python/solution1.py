// Counts elements in hashtable.
// Time: O(n + m), Space: O(min(n + m))

class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        result = []
        count = {}
        
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        
        for n in nums1:
            count[n] = count.get(n, 0) + 1
        
        for n in nums2:
            if count.get(n, 0) > 0:
                result.append(n)
                count[n] -= 1

        return result


