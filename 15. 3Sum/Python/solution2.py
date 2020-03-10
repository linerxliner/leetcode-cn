# Complexity
#   Time: O(n ^ 2)
#   Space: O(n ^ 3)

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = []
        cnt = {}

        for n in nums:
            cnt[n] = cnt.get(n, 0) + 1

        nums = sorted(cnt.keys())

        for i, n1 in enumerate(nums):
            if n1 == 0 and cnt[n1] >= 3:
                result.append([n1, n1, n1])
            elif n1 != 0 and cnt[n1] >= 2 and -2 * n1 in cnt:
                result.append([n1, n1, -2 * n1])

            if n1 < 0:
                two_sum = -n1
                l = bisect.bisect_left(nums, two_sum - nums[-1], i + 1)
                for n2 in nums[l:bisect.bisect_right(nums, two_sum // 2, l)]:
                    n3 = two_sum - n2
                    if n2 != n3 and n3 in cnt:
                        result.append([n1, n2, n3])

        return result
