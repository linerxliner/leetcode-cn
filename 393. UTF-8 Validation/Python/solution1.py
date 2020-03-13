# Complexity
#   Time: O(n)
#   Space: O(1)

class Solution:
    def validUtf8(self, data: List[int]) -> bool:
        head_idx = 0

        while head_idx < len(data):
            head = data[head_idx]

            char_byte_num = 0
            for i in range(7, -1, -1):
                if (head >> i & 0x1) == 0:
                    break
                char_byte_num += 1
            if char_byte_num == 1 or char_byte_num > 4:
                return False
            if char_byte_num > 0:
                char_byte_num -= 1

            if head_idx + char_byte_num >= len(data):
                return False
            for i in range(head_idx + 1, head_idx + char_byte_num + 1):
                if (data[i] >> 7 & 0x1) != 1 or (data[i] >> 6 & 0x1) != 0:
                    return False
            head_idx += char_byte_num + 1

        return True

