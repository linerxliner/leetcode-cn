// Counts elements in hashtable. Compares two arrays after sorting.
// Time: O(nlogn + mlogm), Space: O(1)

class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        result = []
        
        nums1.sort()
        nums2.sort()
        
        i2 = 0
        for i1 in range(len(nums1)):
            while i2 < len(nums2) and nums1[i1] > nums2[i2]:
                i2 += 1
            if i2 < len(nums2) and nums1[i1] == nums2[i2]:
                result.append(nums1[i1])
                i2 += 1
            if i2 >= len(nums2):
                break

        return result


