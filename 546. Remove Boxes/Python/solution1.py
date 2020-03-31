# Complexity
#   Time: O(n ^ 4)
#   Space: O(n ^ 3)

class Solution:
    def generate_right(self, boxes):
        indexes = {}

        for i in range(self.n - 1, -1, -1):
            self.right[i] = indexes.get(boxes[i], self.n)
            indexes[boxes[i]] = i

    def remove(self, boxes, i, j, k):
        key = '{},{},{}'.format(i, j, k)

        if i >= j:
            return 0
        elif key in self.memo:
            return self.memo[key]

        new_i = i

        while new_i < j - 1 and boxes[new_i] == boxes[new_i + 1]:
            new_i += 1
        prev_k = k + new_i - i + 1
        max_kk = prev_k ** 2 + self.remove(boxes, new_i + 1, j, 0)

        probe = new_i
        while probe < j:
            probe = self.right[probe]
            if probe >= j:
                break
            max_kk = max(max_kk, self.remove(boxes, new_i + 1, probe, 0) + self.remove(boxes, probe, j, prev_k))
            while probe < j - 1 and boxes[probe] == boxes[probe + 1]:
                probe += 1

        self.memo[key] = max_kk

        return max_kk


    def removeBoxes(self, boxes: List[int]) -> int:
        self.n = len(boxes)
        self.memo = {}
        self.right = [self.n] * self.n

        self.generate_right(boxes)

        return self.remove(boxes, 0, self.n, 0)
