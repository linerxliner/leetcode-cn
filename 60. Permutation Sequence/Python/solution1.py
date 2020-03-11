# Complexity
#   Time: O(n)
#   Space: O(n)

class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        result = [0] * n

        factorials = [1] * n
        for i in range(1, n):
            factorials[i] = factorials[i - 1] * i

        k -= 1
        nums = [str(i) for i in range(1, n + 1)]
        for i in range(n - 1, -1, -1):
            result[n - 1 - i] = nums.pop(k // factorials[i])
            k %= factorials[i]

        return ''.join(result)
