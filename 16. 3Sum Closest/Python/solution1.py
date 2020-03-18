# Complexity
#   Time: O(n ^ 2)
#   Space: O(1)

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        three_sum = sum(nums[:3])
        nums.sort()

        for i in range(len(nums) - 2):
            l, r = i + 1, len(nums) - 1

            t = nums[i] + nums[l] + nums[l + 1]
            if t == target:
                return t
            elif t > target:
                if abs(t - target) < abs(three_sum - target):
                    three_sum = t
                continue

            t = nums[i] + nums[r - 1] + nums[r]
            if t == target:
                return t
            elif t < target:
                if abs(t - target) < abs(three_sum - target):
                    three_sum = t
                continue

            while l < r:
                t = nums[i] + nums[l] + nums[r]
                if t == target:
                    return t
                else:
                    if t < target:
                        l += 1
                    else:
                        r -= 1
                    if abs(t - target) < abs(three_sum - target):
                        three_sum = t

        return three_sum
