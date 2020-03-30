# Complexity
#   Time: O(n)
#   Space: O(n)
# Description
#   Stack of indexes of max nums before current num.

class Solution:
    MOD = 10 ** 9 + 7

    def sumSubarrayMins(self, A: List[int]) -> int:
        s = []
        sum_min = 0

        min_num = min(A)
        new_A = [min_num - 1] + A + [min_num - 1]

        for i in range(len(new_A)):
            while len(s) > 0 and new_A[s[-1]] > new_A[i]:
                t = s.pop()
                sum_min += new_A[t] * (t - s[-1]) * (i - t)
                sum_min %= self.MOD
            s.append(i)

        return sum_min
