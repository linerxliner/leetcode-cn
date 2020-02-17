class Solution:

    def __init__(self, nums: List[int]):
        self.nums = nums

    def reset(self) -> List[int]:
        """
        Resets the array to its original configuration and return it.
        """
        return self.nums

    def shuffle(self) -> List[int]:
        """
        Returns a random shuffling of the array.
        """
        new_nums = self.nums[:]
        
        for i in range(len(new_nums) - 1, -1, -1):
            e = random.randint(0, i)
            new_nums[e], new_nums[i] = new_nums[i], new_nums[e]
        
        return new_nums


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
