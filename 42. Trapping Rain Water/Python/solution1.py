# Complexity
#   Time: O(n)
#   Space: O(1)

class Solution:
    def trap(self, height: List[int]) -> int:
        units = 0
        left_max, right_max = 0, 0
        l, r = 0, len(height) - 1

        while l <= r:
            if left_max < right_max:
                left_max = max(left_max, height[l])
                units += left_max - height[l]
                l += 1
            else:
                right_max = max(right_max, height[r])
                units += right_max - height[r]
                r -= 1

        return units

