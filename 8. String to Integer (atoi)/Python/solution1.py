# Complexity
#   Time: O(n)
#   Space: O(1)

class Solution:
    INT_MAX = 2 ** 31 - 1
    INT_MIN = -2 ** 31

    def myAtoi(self, s: str) -> int:
        s = s.strip()
        if len(s) == 0:
            return 0

        positive = True
        if s[0] == '-' or s[0] == '+':
            positive = s[0] == '+'
            s = s[1:]

        num = 0
        for c in s:
            if c.isdigit():
                num *= 10
                if positive:
                    num += int(c)
                    if num > self.INT_MAX:
                        return self.INT_MAX
                else:
                    num -= int(c)
                    if num < self.INT_MIN:
                        return self.INT_MIN
            else:
                break

        return num

