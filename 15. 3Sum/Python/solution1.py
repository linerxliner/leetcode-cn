# Complexity
#   Time: O(n ^ 2)
#   Space: O(n ^ 3)

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = []

        nums.sort()

        i = 0
        while i < len(nums) - 2:
            l, r = i + 1, len(nums) - 1

            while l < r:
                if nums[i] + nums[l] + nums[r] < 0:
                    l += 1
                elif nums[i] + nums[l] + nums[r] > 0:
                    r -= 1
                else:
                    result.append([nums[i], nums[l], nums[r]])
                    while l < r and nums[l] == nums[l + 1]:
                        l += 1
                    while l < r and nums[r - 1] == nums[r]:
                        r -= 1
                    l += 1
                    r -= 1

            while i < len(nums) - 1 and nums[i] == nums[i + 1]:
                i += 1

            i += 1

        return result
