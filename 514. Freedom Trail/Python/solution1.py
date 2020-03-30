# Complexity
#   Time: O(m * n ^ 2)
#   Space: O(n)

class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        m, n = len(key), len(ring)
        ring_map = {}
        prev_dp = [[0, 0]]
        min_steps = sys.maxsize

        for i, c in enumerate(ring):
            if c not in ring_map:
                ring_map[c] = []
            ring_map[c].append(i)

        for i in range(m):
            curr_dp = []
            for j in ring_map[key[i]]:
                curr_dp.append([j, sys.maxsize])
                for k, s in prev_dp:
                    d = abs(k - j)
                    curr_dp[-1][1] = min(curr_dp[-1][1], s + d + 1, s + n - d + 1)
            prev_dp = curr_dp

        for i, s in prev_dp:
            min_steps = min(min_steps, s)

        return min_steps
