// Fenwick Tree.
// Time: O(nlogn), Space: O(n)

class Solution:
    class FenwickTree(object):
        def __init__(self, n):
            self.len = n
            self.tree = [0] * (n + 1)
        
        def low_bit(self, idx):
            return idx & -idx
        
        def parent(self, idx):
            return idx + self.low_bit(idx)
        
        def child(self, idx):
            return idx - self.low_bit(idx)
        
        def update(self, idx, delta):
            while idx <= self.len:
                self.tree[idx] += delta
                idx = self.parent(idx)
        
        def query(self, idx):
            cnt = 0
            while idx > 0:
                cnt += self.tree[idx]
                idx = self.child(idx)
            return cnt

    def countSmaller(self, nums: List[int]) -> List[int]:
        fenwick_tree = self.FenwickTree(len(nums))
        indexes = [i for i in range(len(nums))]
        indexes.sort(key=lambda x: nums[x])
        ranks = [0] * len(nums)
        result = []
        
        rank = 1
        for i in range(len(indexes)):
            ranks[indexes[i]] = rank
            if i < len(indexes) - 1 and nums[indexes[i]] != nums[indexes[i + 1]]:
                rank += 1
        
        for i in range(len(nums) - 1, -1, -1):
            result.append(fenwick_tree.query(ranks[i] - 1))
            fenwick_tree.update(ranks[i], 1)
        
        return reversed(result)
