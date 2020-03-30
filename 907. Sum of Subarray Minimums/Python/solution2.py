# Complexity
#   Time: O(n)
#   Space: O(n)
# Description
#   Stack of (val, cnt) incidating min num and it's cnt from i to j.

class Solution:
    MOD = 10 ** 9 + 7

    def sumSubarrayMins(self, A: List[int]) -> int:
        s = []
        t = 0
        sum_min = 0

        for i in range(len(A)):
            cnt = 1
            while s and s[-1][0] >= A[i]:
                prev_val, prev_cnt = s.pop()
                t -= prev_val * prev_cnt
                cnt += prev_cnt
            s.append([A[i], cnt])
            t += A[i] * cnt
            sum_min += t
            sum_min %= self.MOD

        return sum_min
