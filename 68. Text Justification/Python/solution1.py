# Complexity
#   Time: O(n)
#   Space: O(n)

import math

class Solution:
    def generate_line(self, line, maxWidth):
        if len(line) == 1:
            return line[0].ljust(maxWidth)

        interval_num, blank_num = len(line) - 1, maxWidth - len(''.join(line))
        result = line[0]

        longer_num = blank_num % interval_num
        blank_len = blank_num // interval_num

        for i, w in enumerate(line[1:]):
            result += ' ' * (blank_len + (1 if i < longer_num else 0) ) + w

        return result

    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        result = []
        line = []
        char_num = 0

        for w in words:
            if len(line) != 0 and char_num + 1 + len(w) > maxWidth:
                result.append(self.generate_line(line, maxWidth))
                line.clear()
                char_num = 0

            char_num += (0 if len(line) == 0 else 1) + len(w)
            line.append(w)

        result.append(' '.join(line).ljust(maxWidth))

        return result

