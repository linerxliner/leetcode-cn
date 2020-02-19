class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        cnt = 0
        two_sum_tuple = {}
        
        for a in A:
            for b in B:
                two_sum_tuple[a + b] = two_sum_tuple.get(a + b, 0) + 1
        for c in C:
            for d in D:
                cnt += two_sum_tuple.get(-(c + d), 0)
        
        return cnt
