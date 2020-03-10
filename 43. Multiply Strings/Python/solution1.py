# Complexity
#   Time: O(n * m)
#   Space: O(n + m)

class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        num3 = [0] * (len(num1) + len(num2))

        for i in range(len(num1) - 1, -1, -1):
            for j in range(len(num2) - 1, -1, -1):
                p = int(num1[i]) * int(num2[j]) + num3[i + j + 1]
                num3[i + j + 1] = p % 10
                num3[i + j] += p // 10

        begin = 0
        for d in num3:
            if d == 0:
                begin += 1
            else:
                break
        num3 = num3[begin:]

        return ''.join(map(str, num3)) if num3 else '0'
