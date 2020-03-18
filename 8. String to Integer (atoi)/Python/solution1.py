# Complexity
#   Time: O(n)
#   Space: O(1)

import re

class Solution:
    INT_MAX = 2 ** 31 - 1
    INT_MIN = -2 ** 31

    def myAtoi(self, str: str) -> int:
        return max(self.INT_MIN, min(self.INT_MAX, int(*re.findall(r'^[\-\+]?\d+', str.strip()))))

